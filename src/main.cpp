#include "test.h"
#include <thread>
#include <string>
#include <iostream>
#include <chrono>
#include <boost/bind.hpp>
// #include <boost/thread.hpp>
#include <boost/asio.hpp>
#include <boost/asio/io_service.hpp>
#include "io_service_test.h"

using namespace std;

void threadgo() {
    while (true) {
        cout << "thread go: " << endl;
        sleep(3);
    }
    
}

int main() {
    std::string hello = test::hello();
    cout << "hello: " << hello << endl;
    std::this_thread::sleep_for(std::chrono::seconds(1));
    cout << "version: " << test::get_version() << endl;
    // try {
    //     shared_ptr<thread> t;
    //     t.reset(new thread(threadgo));
    //     t->join();
    // } catch (exception& e) {
    //     cout << e.what() << endl;
    // }
    io::io_init();

    return 0;
}