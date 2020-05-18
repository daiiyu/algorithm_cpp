#include <iostream>
#include <cstdlib>
using namespace std;


class Solution {
public:
    static int fib(int n) {
        
        if(n ==0 )
            return 0;
        else if(n == 1)
            return 1;
        else{
            int F0 = 0;
            int F1 = 1;
            int tmp;
            for(int i=0, j=1; j<n; ++i,++j)
            {
                tmp = F1;
                F1+=F0;
                F0 = tmp;
            }
            return F1;
        }
    }
};
int main(int argc, char ** argv)
{
    if(argc == 2)
    {
        int n = atoi(argv[1]);
        cout<<"input:"<<n<<"\t";
        cout<<Solution::fib(n)<<endl;
    }
    else{
   cout<<"arguemnt number error"<<endl;
    cout<<"usage : ./fibonacci 2"<<endl;

    }
 }