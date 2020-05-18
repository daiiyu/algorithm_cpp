//
// Created by zouda on 2020/4/23.
//

#ifndef ALGORITHM_TREENODE_H
#define ALGORITHM_TREENODE_H
#include <memory>

template<typename  T=int>
class TreeNode
{
public:
    T data;
    std::shared_ptr<TreeNode> left;
    std::shared_ptr<TreeNode> right;

};
#endif //ALGORITHM_TREENODE_H
