#include "io_service_test.h"
using namespace std;



void io::io_init() {
    shared_ptr<thread> work_thread;
    work_thread.reset(new thread(io_work));
    work_thread->join();
}


void io::io_start(int num){
    cout << "start " << num << "-------------------->" << endl;
}

void io::io_work() {
    boost::asio::io_service io_service;
    int count = 0;
    while(count < 5) {
        io_service.post(boost::bind(&io::io_start, count));
        count++;
        cout << "post " << count << endl;
        sleep(1);
    }
    io_service.run();

}