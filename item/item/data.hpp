#ifndef __MY_DATA__
#define __MY_DATA__
#include <mysql/mysql.h>
#include <iostream>

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
    static bool MysqlQuery(MYSQL* my)
    {

    }
}






#endif