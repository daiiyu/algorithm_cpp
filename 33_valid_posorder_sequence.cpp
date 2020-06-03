//
// Created by zouda on 2020/5/18.
//
// solution 已经通过leetcode 运行、
#include "base.hpp"

class Solution {
public:
    using DataIter = vector<int>::const_iterator;
    bool verifyPostorder(vector<int>& postorder) {

        return verify(postorder.begin(), postorder.end());
    }

    bool verify(DataIter first_iter, DataIter end_iter)
    {
        if( (end_iter - first_iter) <= 1)
            return true;


        auto right_end_iter = end_iter -1;
        const int root = *right_end_iter;


        //找到第一个 大于 root的元素
        auto comp1 = std::bind(less<int>(), root, placeholders::_1);
        auto right_first_iter = std::find_if(first_iter, right_end_iter, comp1);
        cout<<*right_first_iter<<endl;

        //在 [0, right_first_iter),[rifht_first_iter, right_end_iter)[root]
        //在右子树的区间[rifht_first_iter, right_end_iter)中寻找一个小于root的值。
        auto comp2=  std::bind(less<int>(), placeholders::_1, root);
        auto error_element = std::find_if(right_first_iter, right_end_iter, comp2);
        if(error_element !=right_end_iter)
        {
            return false;
        }
        //[0, right_first) 为左子树
        //[right_frist, end_iter()) 右子树
        bool left_tree = verify(first_iter, right_first_iter);
        if(!left_tree)
            return false;
        bool right_tree = verify(right_first_iter, end_iter - 1);
        if(!right_tree)
            return false;

        return true;
    }
};

int main()
{
    vector<int> valid_arr{1,3,2,6,5};
    vector<int> invalid_arr{1,6,3,2,5};

    Solution solution;
    auto r = solution.verifyPostorder(valid_arr);
    auto r2 = solution.verifyPostorder(invalid_arr);
    cout<<r<<endl;
    cout<<r2<<endl;
}