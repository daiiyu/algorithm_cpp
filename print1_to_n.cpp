#include <string>
#include <iostream>

using namespace std;
/*
大数问题： 
负数问题：
*/
class BigNumber
{
public:
    BigNumber(int n)
    {
        if(n<0)
        {
            n_ = 0;
        }else
        {
            n_ =n;
        }
        
            
        number_.assign(std::string(n_ + 1,'0'));
        number_[n_] = '\0';
    }
    void addOne()
    {
        add(1);
    }
    
    void print()
    {
        std::cout<<std::stoi(number_);
    }
private:
    void addOneRecursive(int i)
    {
        if(i < 0)
            return;
        number_[i] += 1;
        if((number_[i]) > '9')
        {
            number_[i] = '0';
            addOneRecursive(1); 
        }
        
    }
    
   
    void add(int num)
    {
        int pos = n_ - 1;
        while(true)
        {
            number_[pos] += num;
            if(number_[pos]  <=  '9' && number_[pos] >='0')
                return;
            else{

                number_[pos] -= 10;
                --pos;
                num = 1;
                continue;
            }
        }
    }
private:
    int n_;
    std::string number_;
};

int main()
{
    int n = 3;
    BigNumber num(n);
    
    for(int i=0; i< 100; ++i)
    {

        num.print();
        num.addOne();
        cout<<"\t";
    }
    cout<<endl;
}