#ifndef __MY_UTIL__
#define __MY_UTIL__
#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fstream>
#include <jsoncpp/json/json.h>
#include <memory>
#include <sstream>
namespace aod
{
    class FileUtil
    {
    private:
        std::string _name; // 文件路径名称

    public:
        FileUtil(const std::string name)
            : _name(name)
        {
        }
        // 判断文件是否存在
        bool Exists()
        {
            // access 的F_OK专门检测文件是否存在
            int ret = access(_name.c_str(), F_OK);
            if (ret != 0)
            {
                std::cout << "file is not Exists" << std::endl;
                return false;
            }
            return true;
        }
        // 获得文件的大小
        size_t Size()
        {
            if (this->Exists() == false)
            {
                return 0;
            }
            struct stat st;
            //stat接口获取文件属性
            int ret = stat(_name.c_str(), &st);
            if(ret != 0)
            {
                std::cout << "get file stat failed!\n";
                return 0;
            }
            return st.st_size;
        }

        //将文件数据读取到body中
        bool GetContent(std::string* body)
        {
            //定义文件对象
            std::ifstream ifs;//定义读取流对象
            //以二进制的方式打开文件
            ifs.open(_name, std::ios::binary);
            if(ifs.is_open() == false)
            {
                std::cout << "open file failed!\n";
                return false;
            }
            size_t flen = this->Size();//获取文件大小
            body->resize(flen);
            ifs.read(&(*body)[0], flen);
            if(ifs.good() == false)
            {
                std::cout << "read file content failed!\n";
                ifs.close();
                return false;
            }
            ifs.close();
            return true;
            
        }



            //把数据从body输出\写入到文件中
        bool SetContent(const std::string& body)
        {
            std::ofstream ofs;
            ofs.open(_name, std::ios::binary);
            if(ofs.is_open() == false)
            {
                std::cout << "file open failed!" <<std::endl;
                return false;
            }
            //将body的数据写入到ofs文件对象中
            ofs.write(body.c_str(), body.size());
            if(ofs.good() == false)
            {
                std::cout << "write file content failed!" << std::endl;
                ofs.close();
                return false;

            }

            ofs.close();
            return true;
        }


        //创建目录
        bool CreateDirectory()
        {
            if(this->Exists())
            {
                return false;
            }
            mkdir(_name.c_str(), 0777);
            return true;
        }

    };

    class JsonUtil
    {

        public:
        //序列化，将value对象序列化为字符串对象
        //封装序列化函数
        
         static bool Serialize(const Json::Value& value, std::string* body)
         {
            //先构造swb的Json对象，再new出sw
            Json::StreamWriterBuilder swb;
            std::unique_ptr<Json::StreamWriter> sw(swb.newStreamWriter());
            

            std::stringstream ss;
            int ret = sw->write(value, &ss);//解析到ss中
            if(ret != 0)
            {
                std::cout << "Serialize failed!\n";
                return false;
            }
            *body = ss.str();
            return true;
         }

            //输出型参数用指针
         static bool UnSerialize(const std::string& body, Json::Value* value)
         {
            Json::CharReaderBuilder crb;
            std::unique_ptr<Json::CharReader> cr(crb.newCharReader());
            std::string err;

            bool ret = cr->parse(body.c_str(),body.c_str()+ body.size(), value, &err);
            if (ret == false)
            {
                std::cout << "UnSerialize failed!\n";
                return false;
            }
            return true;
         }
    };

}

#endif