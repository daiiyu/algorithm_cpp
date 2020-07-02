#include <random>
#include <iostream>
#include "timer.hpp"
//#include "introsort.hpp"
#include <algorithm>
using namespace std;
const int SIZE = 100000000;
int main()
{

    vector<int> data(SIZE);
    default_random_engine e;
    for (size_t i = 0; i < SIZE; ++i) //生成十个随机数
        data.push_back(e());
    {
        Timer timer;
        sort(data.begin(), data.end());
    }
    return 0;
}

