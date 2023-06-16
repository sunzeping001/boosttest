#include "session.h"
#include <thread>
#include "log.h"
#include <vector>
#include "deploy_task.h"
#include <boost/bind.hpp>
#include <boost/function.hpp>
#include "disk_util.h"
#include "template_test.h"

bool g_main_thread_run = 1;
std::shared_ptr<std::thread> m_thread;
std::vector<boost::function<void(std::string, boost::asio::io_service *)>> methods;
std::shared_ptr<boost::asio::io_service> io;

void session::main_thread()
{
    log("main_thread is running------------>");
    if (!methods.empty())
    {
        // log("main_thread is inner------------>");
        for (int i; i < methods.size(); i++)
        {
            log("methods is gooooooo------------>");
            std::string msg = "fuck you" + std::to_string(i);
            methods[i](msg, io.get());
        }
    }
}

void session::init(boost::asio::io_service *ioContext)
{
    io.reset(ioContext);
    deploy::deploy_task task;
    regiest_handle(boost::bind(&deploy::deploy_task::callback, task, _1, _2));
    disk::disk_test disk_test;
    regiest_handle(boost::bind(&disk::disk_test::call_back, disk_test, _1, _2));
    // template_test::car<int> car;
    // regiest_handle(boost::bind(&template_test::car<int>::call_back, car, _1, _2));
    io.get()->post(boost::bind(&session::main_thread));
}

void session::stop()
{
    g_main_thread_run = 0;
}

void session::regiest_handle(boost::function<void(std::string, boost::asio::io_service *)> f)
{
    methods.push_back(f);
}
