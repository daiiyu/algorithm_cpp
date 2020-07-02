//
// Created by daiyuz on 6/26/20.
//
#include "base.hpp"
class Solution {
public:
    bool isStraight(vector<int>& nums) {

        std::map<int, int> coll;//collection
        for(auto x: nums){
            if(coll.find(x) == coll.end())
                coll[x] = 1;
            else
                ++coll[x];

            if(x !=0 && coll[x] > 1)
                return false;
        }
        auto cur = coll.begin();
        while(cur!=coll.end() && (*cur).first==0)
            ++cur;

        auto prev = cur++;
        int total_diff = 0;
        while(cur!=coll.end()){
            int cur_value = cur->first;
            int prev_value = prev->first;
            total_diff += (cur_value - prev_value) -1;
            prev = cur;
            ++cur;
        }
        if(total_diff <= coll[0])
            return true;
        else
            return  false;

    }
};

int main()
{
    std::allocator<>
    vector<int> testCase1{1,2,3,4,5};
    vector<int> testCase2{4,7,5,9,2};
    vector<int> testCase3{0,0,8,5,4};
    Solution solution;
    bool res = solution.isStraight(testCase2);
    cout<<res<<endl;
}