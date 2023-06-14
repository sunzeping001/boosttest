#include "disk_util.h"
#include <unistd.h>
#include <sys/stat.h>

int disk::disk_test::get_disk_info()
{
    struct statfs disk_info;
    std::string path = "/home/szp/Desktop/cproject/boosttest/third_party/third_libs/libboost_atomic.a";
    if (access(path.c_str(), F_OK) != 0)
    {
        log("file state not success");
        return -1;
    }
    if (statfs(path.c_str(), &disk_info) != -1)
    {
        int64_t total_size = disk_info.f_bsize * disk_info.f_blocks;
        int64_t free_size = disk_info.f_bsize * disk_info.f_bavail;
        total_size = total_size >> 30;
        free_size = free_size >> 30;
        log("total size is " + std::to_string(total_size) + "GB");
        log("free_size is " + std::to_string(free_size) + "GB");
    }

    // // 方法二
    // std::string path = "/home/szp/Desktop/cproject/boosttest/third_party/third_libs/libboost_atomic.a";
    // struct stat disk_info;
    // stat(path.c_str(), &disk_info);
    // int64_t size = disk_info.st_size;
    // log("total size is " + std::to_string(size));
    return 0;
}

void disk::disk_test::call_back(std::string name)
{
    get_disk_info();
}