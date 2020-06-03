//
// Created by daiyu on 2020/6/2.
//

#include <iostream>
#include <string>
#include <thread>

using namespace std;

class thread_guard {
    thread &t_;
public:
    explicit thread_guard(thread &t) : t_(t) {}

    virtual ~thread_guard() {
        cout << "protect thread destruction" << endl;
        t_.join();

    }

    thread_guard() = delete;

    thread_guard(const thread_guard &) = delete;

    thread_guard &operator=(const thread_guard &) = delete;
};


int main() {
    auto func = [] { cout << "hello world" << endl; };

    thread t1(func);
    for (int i = 0; i < 100000002; ++i) {}
    thread_guard guard(t1);
}