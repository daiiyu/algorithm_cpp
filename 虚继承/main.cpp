#include <iostream>
#include <cstdio>
using namespace std;
class A
{
public:
    int a;
    void clone(){}
};

class B:virtual  public A
{
    int b;
};
class C:virtual  public A
{
    int c;
};

class D: B,C
{
    int d;
};
int main() {
    printf("A:%d,B:%d,C:%d,D:%d\n",sizeof(A), sizeof(B),sizeof(C), sizeof(D));
    
    return 0;
}
