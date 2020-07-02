//
// Created by daiyuz on 6/22/20.
//
#include "base.hpp"

class Solution {
public:

    int waysToStep(int n) {
        vector<int> f(1024);
        f.clear();
        f.emplace_back(0);
        f.emplace_back(1);
        f.emplace_back(2);
        f.emplace_back(4);



        for(int i=4; i<=n;++i)
        {
            int a_i = 0;

            for(int j = 3; j>=1; --j)
            {
                a_i = (a_i + f[i- j])%1000000007;
            }

            f.push_back(a_i);
        }


        return f[n];

    }
};

int main()
{
    Solution solution;
    cout<<solution.waysToStep(4)<<endl;
}