//
// Created by daiyu on 2020/6/10.
//

//https://leetcode-cn.com/problems/que-shi-de-shu-zi-lcof/
#include "base.hpp"
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        for(auto&x : nums)
            cout<<" ";

        cout<<endl;
        if(nums.empty() || nums[0] != 0)
            return 0;

        int first_pos = 0;
        int last_pos = nums.size() - 1;
        int mid_pos;

        while(first_pos <=last_pos)
        {
            mid_pos = (first_pos + last_pos)/2;
            if(nums[mid_pos] > mid_pos)
            {
                if(nums[mid_pos - 1] == mid_pos - 1)
                    return mid_pos;
                else
                    last_pos = mid_pos - 1;
            }
            else if(nums[mid_pos] == mid_pos)
                first_pos = mid_pos + 1;
        }
        return nums.size();
    }
};

int main()
{
    Solution s;
    //vector<int> arr{0,1,2,3,4,5,6,7,8,9};

    vector<int> arr{1, 2};
    cout<<s.missingNumber(arr)<<endl;
}

