#include "session.h"
#include <thread>
#include "log.h"
#include <vector>
#include "deploy_task.h"
#include <boost/bind.hpp>
#include <boost/function.hpp>

bool g_main_thread_run = 1;
std::shared_ptr<std::thread> m_thread;
std::vector<boost::function<void(std::string)>> methods;

void work_callback(int index, std::string name)
{
    methods[index](name);
}

void session::main_thread()
{
    std::cout << "main_thread is running------------>" << std::endl;
    log("main_thread is running------------>");
    if (!methods.empty())
    {
        // log("main_thread is inner------------>");
        for (int i; i < methods.size(); i++)
        {
            char name[64];
            sprintf(name, "hello %d", i);
            log("methods is gooooooo------------>");
            // std::thread t(work_callback, i, "fuck you");
            // t.join();
            std::string msg = "fuck you" + std::to_string(i);
            methods[i](msg);
        }
    }
}

void session::init()
{
    deploy::deploy_task task;
    regiest_handle(boost::bind(&deploy::deploy_task::callback, task, _1));
    m_thread.reset(new std::thread(main_thread));
    // m_thread->join();
}

void session::stop()
{
    g_main_thread_run = 0;
}

void session::regiest_handle(boost::function<void(std::string)> f)
{
    methods.push_back(f);
}
