//
// Created by daiyuz on 6/29/20.
//
#include "base.hpp"
//https://leetcode-cn.com/problems/li-wu-de-zui-da-jie-zhi-lcof/
//礼物的最大价值

class Solution {
public:
    int maxValue(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid.front().size();
        vector<vector<int>> dp(rows, vector<int>(cols, 0));

        //初始化
        dp[0][0] = grid[0][0];
        for(int i=1; i<cols; ++i){
            dp[0][i] = grid[0][i] + dp[0][i-1];
        }
        for(int i=1; i<rows; ++i){
            dp[i][0] = grid[i][0] + dp[i-1][0];
        }

        for(int i=1; i<rows; ++i){
            for(int j=1; j< cols; ++j){
                dp[i][j] = std::max(dp[i-1][j], dp[i][j-1]) + grid[i][j];
            }
        }

        return dp[rows-1][cols-1];

    }
};
