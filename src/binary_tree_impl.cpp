#include "binary_tree.hpp"
#include <memory>
#include <queue>
#include <memory>
#include <initializer_list>
#include <stack>
#include <iostream>
using std::shared_ptr;


shared_ptr<Node> generateTree(std::initializer_list<int> l){
    
    if( l.size() == 0)
        return nullptr;
    std::queue<shared_ptr<Node>> que;
    auto root = std::make_shared<Node>();
    
    root->data_ = *l.begin();
    que.push(root);
    auto iter = l.begin();

    while(iter != l.end()){
        std::cout<<"pushing:\t" << *iter<<std::endl;
        auto root = que.front();
        que.pop();

        root->data_ = *iter;
        root->left_ = std::make_shared<Node>();
        root->right_ = std::make_shared<Node>();
        que.push(root->left_);
        que.push(root->right_);
        
        ++iter;
    }
    return root;
}

void DFS_stack(shared_ptr<Node> root){
    std::stack<shared_ptr<Node>> stack_;
    stack_.push(root);

    while(true){
        auto top = stack_.top();
        stack_.pop();
        if(top->data_ = -1)
            return;
    }
}

void DFS(shared_ptr<Node> root)
{
    if(root->data_ == -1)
        return ;
    
    DFS(root->left_);
    std::cout<<root->data_<<"\t";
    DFS(root->right_);
}