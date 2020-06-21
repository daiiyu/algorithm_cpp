#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <stack>
#include <queue>
#include <functional>
#include <unordered_map>
#include <string>
#include <map>
#include <string>
#include <chrono>
using namespace std;

class Time
{
public:
    Time():start_(chrono::steady_clock::now()){}

    void start()
    {
        start_ = std::chrono::steady_clock::now();
    }

    void end()
    {
        auto end = std::chrono::steady_clock::now();
        std::chrono::duration<double, std::micro> elapsed = end - start_; // std::micro 表示以微秒为时间单位
        std::cout<< "time: "  << elapsed.count() << "us" << std::endl;
    }
private:
    decltype(chrono::steady_clock::now()) start_;
};


