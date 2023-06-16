#ifndef TEMPLATE_TEST_H
#define TEMPLATE_TEST_H
#include <iostream>
#include "log.h"
#include <boost/asio/io_service.hpp>
using namespace std;

namespace template_test
{
    template <class T>
    class car
    {
    public:
        void call_back(std::string name, boost::asio::io_service *ioService);

    private:
        string color;
        string name;
    };
} // namespace template_test

#endif