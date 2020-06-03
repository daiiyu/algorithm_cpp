#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numWays(int n) {
        int k = n;
        if (n < 2)
            k = 2;
        vector<int> dp(k + 1, 0);

        dp[0] = 1;
        dp[1] = 1;
        dp[2] = 2;

        //dp[n] = dp[n-1] + dp[n-2]
        for (int i = 2; i < n + 1; ++i) {
            dp[i] = (dp[i - 1] + dp[i - 2]) % (static_cast<int>(1e9) + 7);
        }

        return dp[n];


    }
};

int main() {
    Solution s;
    for (int i = 0; i <= 100; ++i) {
        cout << s.numWays(i) << endl;
    }

    return 0;
}
