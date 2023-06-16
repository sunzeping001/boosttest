#include "template_test.h"
#include "log.h"
#include <thread>

void work_run()
{
}

template <class T>
void template_test::car<T>::call_back(std::string name, boost::asio::io_service *ioService)
{
    log("template call back is running----------------->");
    // thread t(work_run);
    // t.detech();
}