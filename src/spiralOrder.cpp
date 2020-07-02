//
// Created by daiyuz on 6/24/20.
//

#include "base.hpp"
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        return vector<int>{};
    }

    vector<int> printAcircle(const vector<vector<int>>& matrix)
    {
        vector<int> result;

        int rows = matrix.size();
        int columns = matrix.front().size();

        int top = 0;
        int left = 0;
        int bottom = rows - 1;
        int right = columns - 1;


        while(top<= bottom && left <=right){
            for(int i=left; i<=right; ++i){
                int tmp = matrix[top][i];
                result.push_back(tmp);
                cout<<tmp<<" ";
            }
            for(int i=top+1; i<=bottom; ++i){
                int tmp = matrix[i][right];
                result.push_back(tmp);
                cout<<tmp<<" ";
            }
            for(int i=right -1; i >= left;--i){
                int tmp = matrix[bottom][i];
                result.push_back(tmp);
                cout<<tmp<<" ";
            }
            for(int i=bottom-1; i >=top+1; --i){
                int tmp = matrix[i][left];
                result.push_back(tmp);
                cout<<tmp<<" ";
            }

            ++top;
            ++left;
            --bottom;
            --right;
        }
        cout<<endl;
        return result;

    }
};
int main()
{
    vector<vector<int>> testCase1{{{1,2,3},{4,5,6},{7,8,9}}};
    Solution solution;
    auto  res = (solution.printAcircle(testCase1));
    for(auto s:res){
        cout<<s<<" ";
    }
    cout<<endl;
}
