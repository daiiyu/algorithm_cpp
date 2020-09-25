#include <iostream>
#include <cmath>
#include "vector"
#include <algorithm>
#include <assert.h>
using namespace  std;


//  f(num, c)。 考虑第num个物品，放不放入背包。 从 0- size（）
template<typename Bilaterial>
int f(Bilaterial&w, Bilaterial& v, int num, int c)
{
    if(num>=w.size())
        return 0;
    if(c < w[num]) {
        return f(w,v, num +1, c);
    }else{
        return max(f(w,v, num +1, c), f(w,v, num +1, c-w[num])+ v[num]);
    }
}
template<typename Bilaterial>
int f_dp(Bilaterial&w, Bilaterial& v, int num, int Capacity)
{
    assert(w.size() == v.size());
    int n = w.size();
    if(n==0)
        return 0;
    vector<vector<int>> dp(n, vector<int>(Capacity+1, -1));
    //便利一遍 容量 i代表当前容量
    for(int j=0; j<=Capacity; ++j){
        dp[0][j] = (j >= w[num] ? v[num]: 0); 
    }

    for(int i=1; i<n; ++i){
        for(int j=0; j<=Capacity; ++j){
            dp[i][j] = dp[i-1][j]; 
            
            if(j >= w[i])
                dp[i][j] = max(dp[i][j], dp[i-1][j-w[i]] + v[i]);
        }
    }
    return dp[n-1][Capacity];    
}

template<typename Bilaterial>
int f_dp_better(Bilaterial&w, Bilaterial& v, int Capacity)
{
    assert(w.size() == v.size());
    int n = w.size();
    vector<vector<int>> dp(2, vector<int>(Capacity+1, -1));
    //便利一遍 容量 i代表当前容量
    for(int i=0; i<=Capacity; ++i){
        dp[0][i] = (i >= w[0] ? v[0]: 0);
    }

    for(int i=1; i<n; ++i){
        for(int j=0; j<=Capacity; ++j){
            
            dp[i%2][j] = dp[(i-1)%2][j]; 
            
            if(j >= w[i])
                dp[i%2][j] = max(dp[i%2][j], dp[(i-1)%2][j-w[i%2]] + v[i%2]);
        }
    }
    return dp[(n-1)%2][Capacity];    
}


template<typename  Bilaterial>
int f_dp_better_better(Bilaterial&w, Bilaterial& v, int Capacity){
    assert(w.size() == v.size());
    int n = w.size();
    if(n==0 || Capacity==0)
        return 0;
    vector<int> dp(Capacity+1);
    //便利一遍 容量 i代表当前容量
    for(int j=0; j<=Capacity; ++j){
        dp[j] = (j >= w[0] ? v[0]: 0);
    }

    for(int i=1; i<n; ++i){
        for(int j=Capacity; j>=w[i]; j--){
            dp[j] = max(dp[j], dp[j-w[i]] + v[i]);
        }
    }
    return dp[Capacity];
}
int main()
{
    vector<int> w{1,2,3,4};
    vector<int> v{2,3,2,5};
    int Capacity = 7;

    cout<<f(w,v, 0, Capacity)<<endl;
    cout<<f_dp(w,v, 0, Capacity)<<endl;
    cout<<f_dp_better(w,v, Capacity)<<endl;
    cout<<f_dp_better_better(w,v,Capacity)<<endl;
}
