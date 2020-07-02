//
// Created by daiyuz on 7/2/20.
//

#ifndef ALGORITHM_CPP_UGLY_NUMBER_H
#define ALGORITHM_CPP_UGLY_NUMBER_H
#include "base.hpp"

class SolutionUglyNumber {
public:
    int nthUglyNumber(int n) {
        vector<int> dp(n,0);
        dp[0] = 1;
        int p2=0, p3=0, p5=0;

        for(int i=1; i<n; ++i){
            dp[i] = std::min(dp[p2]*2, std::min(dp[p3]*3, dp[p5]*5));
            if(dp[i] == dp[p2]*2)
                ++p2;
            if(dp[i] == dp[p3]*3)
                ++p3;
            if(dp[i] ==dp[p5]*5)
                ++p5;
        }
        return dp[n-1];
    }
};
#endif //ALGORITHM_CPP_UGLY_NUMBER_H
