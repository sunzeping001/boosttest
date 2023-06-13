#include "session.h"
#include <thread>
#include <iostream>

using namespace std;

int main() {
    session::init();    
    std::this_thread::sleep_for(std::chrono::seconds(2));
    std::cout << "main finished------------->" << std::endl;
    return 0;
}