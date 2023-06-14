#pragma one
#ifndef WORK_HEAD_H
#define WORK_HEAD_H

#include <string>

extern int g_mainthread_run;

typedef void (*g_call_back)(std::string method_name);

#endif