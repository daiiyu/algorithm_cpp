//
// Created by zouda on 2020/5/13.
//
//  psh is at the end;
#include <stack>
#include <iostream>
#include <vector>
using namespace  std;

bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {

    stack<int> stck_;
    auto psh = pushed.begin();
    auto po = popped.begin();
    for( ; psh!=pushed.end(); ++psh)
    {
        stck_.push(*psh);
        while(!stck_.empty() &&  po!= popped.end() &&stck_.top() == *po)
        {
            stck_.pop();
            ++po;
        }
    }
    //  psh is at the end;
    if(stck_.empty())
        return true;
    while(!stck_.empty())
    {
       if(*po != stck_.top())
       {
           return false;
       }else{
           stck_.pop();
       }
    }
}

int main()
{
    vector<int> pushed{1,2,3,4,5};
    vector<int> poped{4,5,3,1,2};
    auto result = validateStackSequences(pushed,poped);

    if(result)
        cout<<"yes"<<endl;
    else
        cout<<"no"<<endl;
}
