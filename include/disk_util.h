#ifndef DISK_UTIL_H
#define DISK_UTIL_H
#include <string>
#include "log.h"
#include <sys/statfs.h>
namespace disk
{
    class disk_test
    {
    public:
        int get_disk_info();

        void call_back(std::string name);
    };
}
#endif