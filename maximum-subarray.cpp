//
// Created by daiyu on 2020/6/2.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <type_traits>

using namespace std;

template<typename Container>
typename Container::iterator findMax(Container &nums) {
    if (nums.empty())
        return nums.end();

    auto iter = nums.begin();
    auto max_iter = iter;
    ++iter;
    while (iter != nums.end()) {
        if (*iter > *max_iter)
            max_iter = iter;

        ++iter;
    }
    return max_iter;
}

class Solution {
public:
    static int maxSubArray(vector<int> &nums) {
        if (nums.size() == 0)
            return 0;
        if (nums.size() == 1)
            return *nums.begin();

        vector<int> dp(nums.size(), 0);
        dp[0] = *nums.begin();

        for (int i = 1; i < nums.size(); ++i) {
            if (dp[i - 1] < 0)
                dp[i] = nums[i];
            else
                dp[i] = dp[i - 1] + nums[i];
        }
        return *findMax(dp);
    }
};

int main() {
    vector<int> testArray{-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int res = Solution::maxSubArray(testArray);
    cout << res << endl;
}