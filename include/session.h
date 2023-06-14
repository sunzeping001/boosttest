#include <string>
#include <iostream>
#include <work_def.h>
#include <boost/function.hpp>

namespace session
{

    void main_thread();

    void init();

    void stop();

    void regiest_handle(boost::function<void(std::string)> f);

}