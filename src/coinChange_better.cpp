//
// Created by daiyuz on 6/19/20.
//
#include "base.hpp"

// 相对于coinChange， 改变函数调用为直接map访问
using Coins= vector<int>;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount == 0)
            return 0;

        buffer.resize(amount+1, INT_MAX_);
        for(auto x:coins)
            buffer[x] = 1;


        for(int i=1; i <=amount; ++i)
        {
            int min = INT_MAX_;
            if(buffer[i] !=INT_MAX_)
                min = buffer[i];
            else
            {
                for(auto a_k : coins)
                {
                    int res;

                    if( (i - a_k) <=0)
                        res = INT_MAX_;
                    else
                        res = buffer[i - a_k];

                    res =  (INT_MAX_ == res? INT_MAX_: res + 1);

                    if(res < min)
                        min = res;
                }
            }
            buffer[i] = min;
        }


        return  buffer[amount] == INT_MAX_? -1: buffer[amount];
    }




private:
    const int INT_MAX_ = numeric_limits<int>::max();
    //buffer[k]代表硬币最小数量， 当金额为amount的时候。
    vector<int> buffer;
    int counter = 0;

};



int main()
{
    //test case;
    Coins coins1{1, 2, 5}; //amount 11
    Coins coins2{2}; // amount 3

    Solution solution;
    int res = solution.coinChange(coins2, 1);
    cout<<res<<endl;
}