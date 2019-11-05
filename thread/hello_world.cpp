#include <thread>
#include <mutex>
#include <future>
#include <condition_variable>
#include <iostream>

#include "thread/proto/test.pb.h"

void hello_world() {
    std::cout << "H W" << std::endl;
}

int main() {
    std::thread t(hello_world);
    t.join();
    std::cout << t.get_id() << std::endl;
    std::thread t1([](){ std::cout << "Hello world" << std::endl; });
    t1.join();
    std::cout << "XX: " << std::thread::hardware_concurrency() << std::endl;


    std::future<void> func = std::async([]() { std::cout << "Time is up\n"; });
    func.get();


    std::mutex m;
    std::scoped_lock<std::mutex> l(m);
    demo::Person person;
    person.set_name("hi");
    std::cout << person.name() << std::endl;
    return 0;
}
