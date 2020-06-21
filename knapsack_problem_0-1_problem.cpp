//
// Created by daiyu on 2020/6/11.
//
#include "base.hpp"
template <typename Container>
int F(int i, int C, Container& W, Container& V)
{
    return std::max(F(i -1, C), V[i] +F(i-1, C-W[i]) )
}

int main()
{
    vector<int> w{2,1,3,2};
    vector<int> v{12,10,20,15};


}
