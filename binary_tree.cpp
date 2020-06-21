#include "binary_tree.hpp"

#include <iostream>
#include <vector>
#include <stack>

#include <memory>



using namespace std;

int ipow(int num, int exp)
{
    int i =exp;
    int result = 1;
    while(i-- > 0)
    {
        result *= num;
    }
    return result;
}


class Solution {
public:
    int reverse(int x) {
        stack<pair<int, int>> stack_;
        vector<int> array;
        int tmp = x;
        int count = 0;
        array.emplace_back(x);
        while(true)
        {   tmp = tmp / 10;
            array.emplace_back(std::move(tmp));
            if(tmp == 0)
                break;
        }
        for(int i=0; i< array.size();++i)
        {
            if(0 == array[i+1])
                break;
            array[i] = array[i] - array[i+1] *10;
        }

        int result = 0;
        auto iter = array.begin();
        int size = array.size() -1;
        while(iter!=array.end())
        {
            cout<<*iter<<"\t";
            result += (*iter) * ipow(10, --size);
            ++iter;
        }
        return result;
    }
};
extern "C"{
class Base
{
    public:
    int val=10;
};
class Derived:public Base
{
    public:
    int val=100;
};
}

int main()
{
    Derived d;
    
    return 0 ;
    Solution s;
    cout<<s.reverse(123)<<endl;

    cout<<ipow(10,0)<<endl;
    std::vector<int> array{1,2,3,4,5,6,7,8,9};
    auto root = generateTree({1,2,3,4,5,6,7,8,9});
    cout<<"building tree finish"<<endl;
    DFS(root); cout<<endl;
}
