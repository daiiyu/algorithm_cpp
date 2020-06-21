//
// Created by zouda on 2020/4/23.
//

#ifndef ALGORITHM_LISTNODE_H
#define ALGORITHM_LISTNODE_H

#include <memory>
using std::shared_ptr;

template<typename T = int>
class ListNode
{
public:
    T data;
    shared_ptr<ListNode<T>> prev;
    shared_ptr<ListNode<T>> next;
};

#endif //ALGORITHM_LISTNODE_H
