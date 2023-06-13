#pragma one
#ifndef LOG_H
#define LOG_H

#include <string>

void log(std::string info);

#define LOG(x) log(x)

#endif