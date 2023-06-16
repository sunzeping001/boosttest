#include "deploy_task.h"
#include <thread>
#include <mutex>
#include <condition_variable>
#include "log.h"
#include <iostream>
#include <boost/bind.hpp>

#define PRINT_NUM 10

int count = 0;
std::mutex lock_;
std::condition_variable condition_;
bool is_work = true;
std::shared_ptr<boost::asio::io_service> io_;

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
        if (count == PRINT_NUM)
        {
            is_work = false;
            std::cout << "is_work is " << is_work << std::endl;
        }
        std::cout << "count is " << count << std::endl;
    }
}

void deploy::deploy_task::callback(std::string name, boost::asio::io_service *ioService)
{
    log("callback is running---------->");
    // io_.reset(ioService);
    // io_.get()->post(boost::bind(&deploy::deploy_task::start, this, name));
    start(name);
}

void deploy::deploy_task::start(std::string name)
{
    log("start is running---------->");
    std::thread good(work, name);
    good.detach();
    // io_.get()->post(boost::bind(&work, name));
    // std::this_thread::sleep_for(std::chrono::seconds(3));
    std::thread threads[PRINT_NUM];
    for (int i = 0; i < PRINT_NUM; i++)
    {
        threads[i] = std::thread(awake);
        threads[i].detach();
        // io_.get()->post(boost::bind(&awake));
        std::this_thread::sleep_for(std::chrono::seconds(3));
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