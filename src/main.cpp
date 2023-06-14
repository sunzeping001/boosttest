#include "session.h"
#include <thread>
#include <iostream>

using namespace std;

int main()
{
    try
    {
        session::init();
        while (true)
        {
            std::cout << "main loop------------->" << std::endl;
            sleep(2);
        }
        cout << "finished" << endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
    return 0;
}