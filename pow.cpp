#include <cmath>
#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

static int g_count = 0;
double mypow(double n, int exp)
{
    ++g_count;
    if(exp ==1)
        return n;

    if(exp == 0)
    {
        return 1;
    }
    else if(exp > 0)
    {
        int result =1;

        //odd
        if( (exp & 0x1 )== 1)
        {
            exp -=1;
            return mypow(n*n, exp >>1) * n;   
        }
        else//even
        {
            return mypow(n *n, exp >> 1);
        }
        
        return result;
    }
    else
    {
        return 1.0 / mypow(n, -exp);
    }

}
int main()
{
    cout<<pow(2,static_cast<unsigned>(-1))<<endl;
    cout<< pow(10, 5)<<"\t";
    cout<< pow(10 , 2)<<"\t";
    cout<< pow(10 , -2)<<"\t";
    cout<< pow(0, -2)<<"\t";
    cout<< pow(0, 0)<<endl;

    cout<<pow(2,static_cast<unsigned>(-1))<<endl;
    cout<< mypow(10, 5)<<"\t";


    cout<< mypow(10 , 2)<<"\t";
    cout<< mypow(10 , -2)<<"\t";
    cout<< mypow(0, -2)<<"\t";
    cout<< mypow(0, 0)<<endl;

}