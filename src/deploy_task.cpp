#include "deploy_task.h"
#include <thread>
#include <mutex>
#include <condition_variable>
#include "log.h"
#include <iostream>

int count = 0;
std::mutex lock_;
std::condition_variable condition_;
bool is_work = true;

void awake()
{
    std::unique_lock<std::mutex> lock(lock_);
    log("awake() notify---------------------->");
    condition_.notify_one();
}

void work(std::string name)
{
    while (is_work)
    {
        std::unique_lock<std::mutex> lock(lock_);
        log("before wait gooooooooooooooooooo---------->");
        condition_.wait(lock);
        log("after wait gooooooooooooooooooo---------->");
        char content[100];
        sprintf(content, "work %s is working----------->", name.c_str());
        log(content);
        count++;
        if (count == 2)
        {
            is_work = false;
            std::cout << "is_work is " << is_work << std::endl;
        }
        std::cout << "count is " << count << std::endl;
    }
}

void deploy::deploy_task::callback(std::string name)
{
    log("callback is running---------->");
    start(name);
}

void deploy::deploy_task::start(std::string name)
{
    log("start is running---------->");
    std::thread good(work, name);
    std::thread threads[10];
    for (int i = 0; i < 2; i++)
    {
        threads[i] = std::thread(awake);
        std::this_thread::sleep_for(std::chrono::seconds(1));
        // threads[i].join();
    }
}

void deploy::deploy_task::stop()
{
}

std::string deploy::deploy_task::get_name()
{
    return name;
}

void deploy::deploy_task::set_name(std::string name)
{
    this->name = name;
}