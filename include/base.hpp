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

#ifndef BASE_TOOLS
#define BASE_TOOLS
class TimerCounter
{
public:
    TimerCounter():start_(chrono::steady_clock::now()){}

    inline void start()
    {
        start_ = std::chrono::steady_clock::now();
    }

    inline void end()
    {
        auto end = std::chrono::steady_clock::now();
        std::chrono::duration<double, std::micro> elapsed = end - start_; // std::micro 表示以微秒为时间单位
        std::cout<< "TimerCounter: "  << elapsed.count() << "us" << std::endl;
    }
private:
    decltype(chrono::steady_clock::now()) start_;
};

template<class Sequence>
void printSequence(Sequence&& con){
    for(auto &e: con){
        cout<<e<<" ";
    }
    cout<<endl;
}
#endif