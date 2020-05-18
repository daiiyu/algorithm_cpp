#ifndef BINARY_TREE__
#define BINARY_TREE__

#include <memory>
#include <initializer_list>
using std::shared_ptr;
struct Node
{
public:
    Node()
    :data_(-1)
    {}
    Node(const int&data, std::shared_ptr<Node> left, std::shared_ptr<Node> right)
    :data_(data), left_(left), right_(right){}

    int data_;
    std::shared_ptr<Node> left_;
    std::shared_ptr<Node> right_;
};

shared_ptr<Node> generateTree(std::initializer_list<int> l);
void DFS(shared_ptr<Node> root);
#endif