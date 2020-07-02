//
// Created by daiyu on 2020/6/4.
//
#include <string>
#include "base.hpp"
using namespace  std;


char FirstNotRepeatingChar(const string& str)
{
    if(str.empty())
    {
        return ' ';
    }

    int order = 1;
    unordered_map<char, int> charMap;
    for(auto c: str)
    {
        const auto& charObj = charMap.find(c);
        //如果map中已经有元素了
        if(charObj != charMap.end())
        {
           charObj->second = -1;

        }else{
            charMap.emplace(std::make_pair(c, order++));
        }
    }

    auto curIter = charMap.begin();
    auto minIter = curIter;
    ++curIter;

    while(curIter!=charMap.end())
    {
        printf("(%c,%d)\t", curIter->first, curIter->second);
        if(curIter->second>=0 && curIter->second < minIter->second )
        {
            minIter = curIter;
        }
        ++curIter;
    }


    cout<<endl;
    return minIter->second == -1? ' ': minIter->first;
}

int main()
{
    string str("leetcode");
    cout<<FirstNotRepeatingChar(str)<<endl;
}