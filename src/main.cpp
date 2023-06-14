#include "session.h"
#include <thread>
#include <iostream>
#include "log.h"
#include <boost/asio/io_service.hpp>
#include <boost/bind.hpp>
#include "work_def.h"

using namespace std;

boost::asio::io_service io_service;

void work_thread()
{
    try
    {
        // session::init();
        io_service.post(boost::bind(&session::init, &io_service));
        while (g_mainthread_run)
        {
            log("main loop------------->");
            io_service.run();
            io_service.reset();
            sleep(2);
        }
        log("finished");
    }
    catch (const std::exception &e)
    {
        std::cout << "main exception---->" << e.what() << std::endl;
    }
}

int main()
{
    thread wt(work_thread);
    wt.join();
    return 0;
}