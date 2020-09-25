#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
using namespace std;
int main() {


    //重量
    vector<int> wt {0,2,3,4,5,6,7};
    //价值
    vector<int> val{0,3,4,5,6,7,8};

    int N = wt.size()-1;
    int W = 8;


    //dp[前i个物品][容量]
    vector<vector<int>> dp(N+1, vector<int>(W+1));

    //第一行 置0
    for(int i=0; i<=W; ++i)
    {
        dp[0][i] = 0;
    }
    for(int i=0; i<=N; ++i)
    {
        dp[i][0] = 0;
    }

    for(int i = 1; i<=N; ++i ){
        for(int w=1; w <= W; ++w){

            if(w - wt[i] < 0)
            {
                dp[i][w] = dp[i-1][w];
            }else{
                dp[i][w] = max(dp[i-1]
                        [w-wt[i]] +
                        val[i],
                               dp[i-1][w]);
            }

        }
    }
    for(auto& arr: dp){
        for(auto x: arr){
            cout<<x<<" ";
        }
        cout<<endl;
    }
    cout<< dp[N][W]<<endl;

    return 0;



}