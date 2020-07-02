//
// Created by daiyuz on 6/23/20.
//
#include "base.hpp"

class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(3,0);
        dp[0] = 1;
        dp[1] = 2;

        for_each(dp.begin(), dp.end(), [](int i){cout<<i<<" ";});
        cout<<endl;
        for(int i=2; i<n; ++i)
        {
            int tmp = dp[(i-1)%3] + dp[(i-2)%3];
            dp[i%3] = tmp;
            for_each(dp.begin(), dp.end(), [](int i){cout<<i<<" ";});
            cout<<endl;
        }
        return dp.back();
    }
};

int main()
{
    Solution solution;
    cout<<solution.climbStairs(5)<<endl;
}