#include "util.hpp"
#define ROOT "www"
#include "data.hpp"
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

void DataTest()
{
    aod::TableVideo tb_video;
    Json::Value video;
    video["name"] = "变形金刚";
    video["info"] = "这是一个会变形的机器人，机器人大战，精彩纷呈~!";
	video["video"] = "/video/robot.ma4";
	video["image"] = "/image/robot.jpg";

    tb_video.Insert(video);
	tb_video.SelectAll(&video);
	// tb_video.SelectOne(1, &video);
	// tb_video.SelectLike("金刚", &video);
	std::string body;
	aod::JsonUtil::Serialize(video, &body);
	std::cout << body << std::endl;
}
int main()
{
    // UtilTest();
    // JsonUtilTest();
    DataTest();
    return 0;
}