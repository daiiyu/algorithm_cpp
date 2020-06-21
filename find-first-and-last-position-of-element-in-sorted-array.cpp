//
// Created by daiyu on 2020/6/9.
//
#include "base.hpp"
#include <exception>
using namespace std;
class Solution {
public:
    using iterator = vector<int>::iterator;
    int search(vector<int>& nums, int target) {
        if(nums.size() == 0)
            return 0;
        //printSequence(nums, 0, nums.size() -1);

        int target_pos = binarySearch(nums,target) ;
        if( -1 == target_pos)
            return 0;
        int first = binaryFirstSearch(nums, target, target_pos);
        int last = binaryLastSearch(nums, target, target_pos) ;

        return last - first + 1;
    }
    int binarySearch(vector<int>& nums, int target)
    {
        int first_pos = 0;
        int last_pos = nums.size() -1;
        int mid_pos;

        while(first_pos <=last_pos)
        {
            printSequence(nums, first_pos, last_pos);
            mid_pos = (first_pos + last_pos) / 2;
            if(nums.at(mid_pos) == target)
                return mid_pos;
            else if(target < nums.at(mid_pos) )
                last_pos = mid_pos - 1;
            else
                first_pos = mid_pos + 1;

        }
        if(last_pos > 0 && first_pos == target)
            return last_pos;
        else
            return -1;
    }
    int binaryFirstSearch(vector<int>&nums, int target, int last)
    {
        if (last >=1 && nums.at(last -1 )!=target)
            return last;

        int first_pos = 0;
        int last_pos = last;
        int mid_pos;
        while(first_pos < last_pos)
        {
            mid_pos = (first_pos+last_pos)/2;
            if(nums.at(mid_pos )== target)
            {
                if(nums.at(mid_pos-1) !=target)
                    return mid_pos;
                else
                {
                    last_pos = mid_pos - 1;
                }
            }
            else
            {
                first_pos = mid_pos + 1;
            }
        }
        if(first_pos < nums.size() && first_pos == target)
            return first_pos;
        else
            return -1;
    }

    int binaryLastSearch(vector<int>&nums, int target, int first)
    {
        if ( (first + 1< nums.size()) &&nums.at(first +1 )!=target)
            return first;

        int first_pos = first;
        int last_pos = nums.size() - 1;
        int mid_pos;
        while(first_pos < last_pos)
        {
            //printSequence(nums, first_pos, last_pos);
            mid_pos = (first_pos+last_pos)/2;
            if(nums.at(mid_pos )== target)
            {
                if(nums.at(mid_pos+1) !=target)
                    return mid_pos;
                else
                {
                    first_pos = mid_pos + 1;
                }
            }
            else
            {
                last_pos = mid_pos - 1;
            }
        }
        if(last_pos > 0 && last_pos == target)
            return last_pos;
        else
            return -1;
    }
    void printSequence(vector<int>& nums, int first, int last)
    {
        for(int i =first;i<=last;++i)
        {
            cout<<nums.at(i)<<" ";
        }
        cout<<endl;
    }
};

int main()
{
    Solution solution;
    vector<int> arr{2,2};

    cout<<solution.search(arr, 2)<<endl;
    cout<<__cplusplus<<endl;
}