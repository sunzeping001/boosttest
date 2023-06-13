#include "session.h"
#include <thread>
#include "log.h"

bool g_main_thread_run = 1;
std::shared_ptr<std::thread> m_thread;

void session::main_thread() {
    while(true) {
        // std::cout << "main_thread is running------------>" << std::endl;
        log("main_thread is running------------>");
        std::this_thread::sleep_for(std::chrono::seconds(2));
    }
}

void session::init() {
    m_thread.reset(new std::thread(main_thread));
    m_thread->join();
}

void session::stop() {
    g_main_thread_run = 0;
}

