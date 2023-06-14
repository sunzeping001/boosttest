#include "session.h"
#include <thread>
#include <iostream>
#include "log.h"

using namespace std;

int main()
{
    try
    {
        session::init();
        while (true)
        {
            log("main loop------------->");
            sleep(2);
        }
        log("finished");
    }
    catch (const std::exception &e)
    {
        std::cout << "main exception---->" << e.what() << std::endl;
    }
    return 0;
}