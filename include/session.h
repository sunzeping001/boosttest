#include <string>
#include <iostream>
#include <work_def.h>
#include <boost/function.hpp>
#include <boost/asio/io_service.hpp>

namespace session
{

    void main_thread();

    void init(boost::asio::io_service *ioService);

    void stop();

    void regiest_handle(boost::function<void(std::string, boost::asio::io_service *)> f);
}