#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:

pair<vector<int> ,vector<int>> preorder_partition(vector<int> & preorder, vector<int> &left_inorder)
{
    auto root_iter = left_inorder.end() - 1;
    auto left_last = find(preorder.begin(), preorder.end(), (*root_iter));
    vector<int> left(preorder.begin() + 1, left_last + 1);
    vector<int> right(left_last+1, preorder.end());
    return make_pair(left, right);
    
}
pair<vector<int>, vector<int>> inorder_partition(vector<int> & inorder, int root)
{
    auto inorder_root = find(inorder.begin(), inorder.end(), root);
    vector<int> left_(inorder.begin(), inorder_root);
    vector<int> right_(inorder_root + 1, inorder.end());
    return make_pair(left_, right_);
}
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        TreeNode* root= preorder.begin();
       
        auto in_left_right = inorder_partition(inorder, (*inorder.begin()));
        auto pre_left_right = preorder_partition(preorder, in_left_right.first);

        root->left = buildTree(pre_left_right.first, in_left_right.first);
        root->left = buildTree(pre_left_right.second, in_left_right.second);
        return root;
    }
};


int main()
{

}