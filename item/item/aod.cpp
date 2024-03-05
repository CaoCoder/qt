#include "util.hpp"
#define ROOT "www"
void UtilTest()
{
    
    std::string body;
    aod::FileUtil fu(ROOT);
    fu.CreateDirectory();
    std::cout << aod::FileUtil("./www/index.html").Size();
    aod::FileUtil("./www/index.html").GetContent(&body);
    std::cout << body;
}

void JsonUtilTest()
{
    Json::Value value;
    value["姓名"] = "张三";
     value["年龄"] = 18;
      value["性别"] = "男";
       value["成绩"].append(51);
       value["成绩"].append(544);
       value["成绩"].append(56);
    std::string body;
    aod::JsonUtil s1;
    s1.Serialize(value, &body);
    std::cout << body <<std::endl;
  Json::Value stu;
    s1.UnSerialize(body, &stu);

    std::cout << stu["姓名"].asCString() ;
}
int main()
{
    // UtilTest();
    JsonUtilTest();
    return 0;
}