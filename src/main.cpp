#include "session.h"
#include <thread>
#include <iostream>
#include "log.h"
#include <boost/asio/io_service.hpp>
#include <boost/bind.hpp>
#include "work_def.h"
#include <execinfo.h>
#include <unistd.h>
#include <signal.h>

using namespace std;

boost::asio::io_service io_service;

void signal_handler(int sig)
{
    void *array[10];
    size_t size;
    size = backtrace(array, 10);
    FILE *fp = fopen("../crash.log", "a");
    if (fp != NULL)
    {
        fprintf(fp, "Error: signal %d\n", sig);
        backtrace_symbols_fd(array, size, fileno(fp));
        fclose(fp);
    }
    exit(1); // exit the program
}

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
    signal(SIGSEGV, signal_handler);
    thread wt(work_thread);
    wt.join();
    return 0;
}