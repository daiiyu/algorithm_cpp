//
// Created by daiyuz on 6/28/20.
//
#include "base.hpp"
#include <cmath>

class Solution {
public:

    const int NUM_ASPECT = 6; // 色子的面数
    vector<double> twoSum(int n) {

        const int ALL = pow(NUM_ASPECT, n);
        dp.resize(n+1,vector<int>(NUM_ASPECT*n+1));
        //下标从1开始
        for(int i=1; i<=NUM_ASPECT;++i){
            dp[1][i] = 1;
        }
        cout<<"*************before dp****************"<<endl;
        for(int i=1; i<dp.size();++i){
            for(int j =i; j<dp[i].size();++j){
                cout<<dp[i][j]<<"\t";
            }
            cout<<endl;
        }
        cout<<endl;
        //dp
        for(int i=2; i<=n; ++i){
            for(int j=i; j<= i*NUM_ASPECT;++j){
                for(int cur =1; cur<=NUM_ASPECT;++cur){
                    if(j-cur<=0)
                        break;
                    dp[i][j] += dp[i -1][j-cur];
                }

            }
        }

        cout<<"*************after dp****************"<<endl;
        for(int i=1; i<dp.size();++i){
            for(int j =i; j<dp[i].size();++j){
                cout<<dp[i][j]<<"\t";
            }
            cout<<endl;
        }

        cout<<endl;
        vector<double> result;
        for(int i=n; i<= NUM_ASPECT*n; ++i){
            double tmp = dp[n][i];
            tmp /= (ALL*1.0);
                result.push_back(tmp);
            printf("(%d, %d):%f ", n, i,tmp);
        }
        cout<<endl;

        return result;
    }



private:
    vector<vector<int>> dp;
};


int main()
{
    Solution solution;

    solution.twoSum(2);
}
