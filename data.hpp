#ifndef __MY_DATA__
#define __MY_DATA__
#include "util.hpp"
#include <mysql/mysql.h>
#include <iostream>
#include <mutex>
#include <jsoncpp/json/json.h>
#include <stdio.h>
namespace aod
{

    //mysql初始化   
#define HOST "127.0.0.1"
#define USER "root"
#define PASS "123456"
#define NAME "aod_system"
    static MYSQL* MysqlInit()
    {
        //初始化mysql接口
        MYSQL* mysql = mysql_init(NULL);
        if (mysql == NULL)
        {
            std::cout << "init mysql instance failed!\n";
            return NULL;
        }
        //句柄， 主机名 用户名  密码 数据库名
        if(mysql_real_connect(mysql,HOST, USER, PASS, NAME, 0, NULL, 0) == NULL)
        {
            std::cout << "connect mysql server failed\n";
            mysql_close(mysql);//呼应init
            return NULL;
        }
        //设置字符编码
        mysql_set_character_set(mysql, "utf8");
        return mysql;

    }

    static void MysqlDestory(MYSQL* mysql)
    {
        if(mysql != NULL)
        {
        mysql_close(mysql);

        }
        return ;
    }
    //封装查询
    static bool MysqlQuery(MYSQL* mysql, const std::string& sql)
    {
        int ret = mysql_query(mysql, sql.c_str());
        if(ret != 0)
        {
            std::cout <<sql << std::endl;
            std::cout <<mysql_error(mysql) << std::endl;
            return false;
        }
        return true;
    }

    class TableVideo
    {
        private:
            MYSQL* _mysql;
            std::mutex _mutex;
        public:
            TableVideo()
            {
                _mysql = MysqlInit();//，初始化mysql，获得句柄
                if(_mysql == NULL)
                {
                    exit(-1);
                }
            }

            ~TableVideo()
            {
                MysqlDestory(_mysql);
            }

            bool Insert(const Json::Value& video)
            {
                std::string sql;
                sql.resize(4096 + video["info"].asString().size());
                #define INSERT_VIDEO "insert tb_video values(null, '%s', '%s', '%s', '%s');"
                if(video["name"].asString().size() == 0)
                {
                    return false;
                }
                //将sql语句写入到sql变量中
                sprintf(&sql[0], INSERT_VIDEO,video["name"].asCString(),
                    video["info"].asCString(),
                    video["video"].asCString(),
                    video["image"].asCString());

                return MysqlQuery(_mysql, sql);//调用查询

            }

            //更新数据库
            bool Update(int video_id, const Json::Value& video)
            {
                std::string sql;
                sql.resize(4096 + video["info"].asString().size());//防止简介过长
				#define UPDATE_VIDEO "update tb_video set name='%s', info='%s' where id=%d;"
                sprintf(&sql[0], UPDATE_VIDEO, video["name"].asCString(),
						video["info"].asCString(), video_id);

                        return MysqlQuery(_mysql, sql);
            }

            //删除
            bool Delete(int video_id)
            {
                #define DELETE_VIDEO "delete from tb_video where id=%d;"
                char sql[1024] = {0};
                sprintf(sql, DELETE_VIDEO, video_id);
                return MysqlQuery(_mysql, sql);
            }

            //查询全部

            bool SelectAll(Json::Value* videos)
            {
                #define SELECTALL_VIDEO "select * from tb_video;"
                _mutex.lock();//多线程访问需要先加锁，省的数据改变，查出来的不对
                bool ret = MysqlQuery(_mysql, SELECTALL_VIDEO);
                if(ret == false)
                {
                    _mutex.unlock();
                    return false;
                }

                //
                MYSQL_RES* res = mysql_store_result(_mysql);//返回结果集
                if(res ==NULL)
                {
                    std::cout << "mysql store result failed!\n";
                    _mutex.unlock();
                    return false;
                }
                //走到这里，意味着可以拿数据了，所以要先解锁
                _mutex.unlock();
                int num_rows = mysql_num_rows(res);//拿出所有行
                for(int i = 0; i < num_rows; i++)
                {
                    //拿出一行
                    MYSQL_ROW row = mysql_fetch_row(res);
                    Json::Value video;
                    video["id"] = atoi(row[0]);
                    video["name"] = row[1];
					video["info"] = row[2];
					video["video"] = row[3];
					video["image"] = row[4];
                    videos->append(video);//添加一行数据
                }
                //释放结果集
                mysql_free_result(res);
                return true;
                
            }
            bool SelectOne(int video_id, Json::Value* video)
            {
               		#define SELECTONE_VIDEO "select * from tb_video where id=%d;"
				char sql[1024] = {0};
				sprintf(sql, SELECTONE_VIDEO, video_id);
				_mutex.lock();//-----lock start 保护查询与保存结果到本地的过程

                //加锁后开始查询
                bool ret = MysqlQuery(_mysql, sql);
                if(ret == false)
                {
                    _mutex.unlock();
                    return false;
                }
                _mutex.unlock();


                //到这里开始打印

                //先存储结果集
                MYSQL_RES *res = mysql_store_result(_mysql);
				if (res == NULL) {
					std::cout << "mysql store result failed!\n";
					_mutex.unlock();
					return false;
				}
                int num_rows = mysql_num_rows(res);

                //假如获取到的数据不是一行，说明是错误的
                if(num_rows != 1)
                {
                    std::cout << "no data" << std::endl;
                    mysql_free_result(res);//释放结果集
                    return false;
                }

                MYSQL_ROW row = mysql_fetch_row(res);
                (*video)["id"] = video_id;
                (*video)["name"] = row[1];
				(*video)["info"] = row[2];
				(*video)["video"] = row[3];
				(*video)["image"] = row[4];
                mysql_free_result(res);
                return true;
            }

            //模糊查询
            bool SelectLike(const std::string& key, Json::Value* videos)
            {
                #define SELECTLIKE_VIDEO "select * from tb_video where name like '%%%s%%';"
                char sql[1024] = {0};
                sprintf(sql, SELECTLIKE_VIDEO, key.c_str());
                _mutex.lock();//保护 查询过程 和 保存结果到本地的过程
                bool ret = MysqlQuery(_mysql, sql);
                if(ret == false)
                {
                    _mutex.unlock();
                    return false;
                }
                MYSQL_RES *res = mysql_store_result(_mysql);
				if (res == NULL) {
					std::cout << "mysql store result failed!\n";
					_mutex.unlock();
					return false;
				}
				_mutex.unlock();//------lock end
                		int num_rows = mysql_num_rows(res);
				for (int i = 0; i < num_rows; i++) {
					MYSQL_ROW row = mysql_fetch_row(res);
					Json::Value video;
					video["id"] = atoi(row[0]);
					video["name"] = row[1];
					video["info"] = row[2];
					video["video"] = row[3];
					video["image"] = row[4];
					videos->append(video);
				}
				mysql_free_result(res);
				return true;

            }








    };


}






#endif