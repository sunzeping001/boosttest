#include <thread>
#include <string>
#include <iostream>
#include <chrono>
#include <boost/bind.hpp>
#include <boost/asio.hpp>
#include <boost/asio/io_service.hpp>

namespace io
{
    void io_init();

    void io_start(int num);

    void io_work();
} // namespace io
