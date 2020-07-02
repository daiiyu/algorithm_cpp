//
// Created by daiyuz on 6/28/20.
//

#include "base.hpp"

class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        return solution2(target);
    }

    //暴力求解
    vector<vector<int>> solution1(int target) {
        vector<vector<int>> result;
        vector<int> intermediateArray(128);
        int end = (target / 2) + 1;
        for(int i=1; i<= end;++i){
            int sum = 0;
            intermediateArray.clear();
            for(int j=i; j<=target  ; ++j){
                sum +=j;
                intermediateArray.push_back(j);
                if(sum < target)
                    continue;
                if(sum > target){
                    break;
                }else if(sum == target){
                    result.push_back(intermediateArray);
                }
            }
        }
        return result;
    }

    //滑动窗口, 伸缩窗口
    vector<vector<int>> solution2(int target) {
        vector<vector<int>> result;


        //[i ,j]窗口，闭区间
        int end = (target / 2) + 1;
        int i=1; int j=2;

        int sum = 1;
        while(j <=end){
            //正常， j 向右，扩展
            for( ;j<=target; ++j){
                sum +=j;

                if(sum < target)
                    continue;
                if(sum > target){
                    break;
                }else {//(sum == target)
                    push(result, i, j);
                }
            }
            // i 向右， 收缩
            for(; i < j; ){
                sum-=i;
                ++i;
                if(sum > target)
                    continue;
                if(sum < target){
                    break;
                }else{ //(sum == target)
                    push(result, i, j);
                    ++j;
                    break;
                }
            }
        }
        return result;
    }

    void push(vector<vector<int>>& result, int i, int j){
        vector<int> intermediateArray(256);
        intermediateArray.clear();
        for(; i<=j; ++i){
            intermediateArray.emplace_back(i);
        }
        result.push_back(std::move(intermediateArray));
    }
};

int main()
{
    Solution solution;
    auto result = solution.solution2(15);
    for(auto & tmp:result){
        printSequence(tmp);
        cout<<endl;
    }
}