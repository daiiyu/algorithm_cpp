#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    int cuttingRope(int n) {
        n = n > 6? n: 6;
        vector<int> buf(n+1, -1);

        buf[2] = 1;
        buf[3] = 2;
        buf[4] = 4;
        buf[5] = 6;
        buf[6] = 9;

        return dfs(buf, n);
    }

    int dfs(vector<int>& buf, int n){

        if(n >=2&& buf[n] > 0)
            return buf[n];
        int res=0;
        for(int i=1; i<=n-2; ++i)
        {
            res =std::max(res, i * dfs(buf, n -i));
        }
        buf[n] = res;
        return res;

    }
};

int main() {
    Solution solution;
    int res = solution.cuttingRope(30);

    std::cout << res<< std::endl;
    return 0;
}
