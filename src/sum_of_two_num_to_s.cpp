#include "base.hpp"
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> arr;

        int other;

        for(int i=0;i < nums.size(); ++i){
            other = target - nums[i];

            int res = binary_search(nums, other, i + 1, nums.size() -1);
            if(res < 0)
                res = binary_search(nums, other, 0, i - 1);
            if(res > 0 && res < nums.size() && nums[res] == other)
            {
                arr.push_back(nums[i]);
                arr.push_back(other);
                break;
            }

        }
        return arr;
    }

    int binary_search(vector<int>&nums, int target, int i, int j)
    {
        if(j<i || j <0)
        {
            return -1;
        }
        int mid;

        while(i <= j)
        {
            mid = (i+j)/2;
            if(nums[mid] == target)
                return mid;
            else if(target < nums[mid])
                j = mid - 1;
            else
                i = mid + 1;
        }
        return i;
    }
};

int main()
{
    Solution s;
    vector<int> arr{14,15,16,22,53,60};
    cout<< s.binary_search(arr, 7, 1, 3)<<endl;

    auto res = s.twoSum(arr, 76);
    for(auto x: res)
        cout<<x<<" ";
    cout<<endl;
}