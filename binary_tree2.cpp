//
// Created by zouda on 2020/5/15.
//


// * Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };


#include <list>

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {

        std::queue<TreeNode*> upper;
        std::queue<TreeNode*> lower;
        upper.push(root);
        std::vector<int> level;
        vector<vector<int>> result;

        while(!upper.empty() || !lower.empty())
        {
            level.clear();
            // handle a point
            while(!upper.empty())
            {
                auto cur = upper.front();

                level.push_back(cur->val);
                if(cur->left !=nullptr)
                    lower.push(cur->left);
                if(cur->right != nullptr)
                    lower.push(cur->right);
                upper.pop();
            }
            result.emplace_back(level);
            swap(upper, lower);// swap the content;
        }
        return result;

    }
};

int main()
{
    Solution s;
    s.levelOrder();
}