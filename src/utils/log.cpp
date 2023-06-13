#include "log.h"
#include <string>
#include <iostream>
#include <thread>
#include <ctime>
#include <chrono>
#include <sys/types.h>
#include <unistd.h>
#include <thread>
using namespace std;

string TAG = "XSGG";

std::time_t getTimeStamp()
{
    std::chrono::time_point<std::chrono::system_clock,std::chrono::milliseconds> tp = std::chrono::time_point_cast<std::chrono::milliseconds>(std::chrono::system_clock::now());
    auto tmp=std::chrono::duration_cast<std::chrono::milliseconds>(tp.time_since_epoch());
    std::time_t timestamp = tmp.count();
    return timestamp;
}
std::string gettm(std::time_t timestamp)
{
    std::time_t milli = timestamp/*+ (std::time_t)8*60*60*1000*/;//此处转化为东八区北京时间，如果是其它时区需要按需求修改
    auto mTime = std::chrono::milliseconds(milli);
    auto tp=std::chrono::time_point<std::chrono::system_clock,std::chrono::milliseconds>(mTime);
    auto tt = std::chrono::system_clock::to_time_t(tp);
    std::tm* now = std::gmtime(&tt);
    char data[64];
    sprintf(data, "%4d-%02d-%02d %02d:%02d:%02d.%d\n",now->tm_year+1900,now->tm_mon+1,now->tm_mday,now->tm_hour,now->tm_min,now->tm_sec, milli%1000);
    return data;
}

void log(std::string info) {
    cout << "[" << gettm(getTimeStamp()) << " " << getpid() << ":" << std::this_thread::get_id() << "]" << TAG << " " << info.c_str() << endl;
}