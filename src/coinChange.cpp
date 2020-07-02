//
// Created by daiyuz on 6/19/20.
//
#include "base.hpp"

using Coins= vector<int>;
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {

        for(auto x:coins)
            buffer[x] = 1;

        for(int i=0; i <=amount; ++i)
        {
            f(i, coins);
        }


        cout<<"counter:"<<counter<<endl;
        return  buffer[amount] == INT_MAX? -1: buffer[amount];
    }

private:
    int f(int amount, const Coins& coins)
    {
        ++counter;
        if(amount <=0)
            return INT_MAX;

        if(buffer.find(amount) != buffer.end())
            return buffer[amount];
        int min = INT_MAX;
        for(auto a_k : coins)
        {
            //优化点
            //因为我们是0->n向后推进的，所以 后面的一定已经算出来了，我们不需要递归调用。
            int res = f(amount - a_k, coins);
            res =  (INT_MAX == res? INT_MAX: res + 1);

            if(res < min)
                min = res;
        }
        buffer[amount] = min;

        return min;
    }

private:
    const int INT_MAX = numeric_limits<int>::max();
    //buffer[k]代表硬币最小数量， 当金额为amount的时候。
    unordered_map<int,int> buffer;
    int counter = 0;

};



int main()
{
    //test case;
    Coins coins1{1, 2, 5}; //amount 11
    Coins coins2{2}; // amount 3

    Solution solution;
    int res = solution.coinChange(coins2, 3);
    cout<<res<<endl;
}