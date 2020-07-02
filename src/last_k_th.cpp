#include "base.hpp"



list<int>::iterator last_k(list<int>& lst, int k)
{

    if(lst.size() < k || k<=0)    
     return lst.end();   

    auto cur = lst.begin();
    auto guard = cur;
    
    for(int i=0; i<k; ++i)
    {
        ++cur;
    }
    while(cur != lst.end())
    {
        ++cur;
        ++guard;
    }
    return guard;
}
int main()
{
    list<int> lst;
    for(int i=100; i>0; --i)
        lst.push_back(i);

    auto iter = last_k(lst, 15);
    cout<<*iter<<endl;
}