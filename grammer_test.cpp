//
// Created by zouda on 2020/5/18.
//

#include "base.hpp"
using namespace  placeholders;
void print(int a, int b, int c)
{
    cout<< a <<"\t"<<b<<"\t"<<c<<endl;
}

class Base
{
public:
   void calculate() ;
   virtual void calculate_vir();
   inline void calculate_inl();
    ~Base(){}
private:
    int x = 1;
};

void Base::calculate()
{
    x += 1;
}
void Base::calculate_vir()
{
    x += 1;
}
void inline Base::calculate_inl()
{
    x += 1;
}

class Derived: public Base
{
public:
   void calculate_virtual();
   int y = 0;
};
void Derived::calculate_virtual() {
    y+=1;
}
void test(){
    Time time1;
    auto* derived = new Derived;
    time1.start();

    for(int i=0; i<1000000; ++i)
    {
        derived->calculate();
    }
    time1.end();
}
void test2(){
    Time time1;
    auto* derived = new Derived;
    time1.start();

    for(int i=0; i<1000000; ++i)
    {
        derived->calculate_virtual();
    }
    time1.end();
}
void test3(){
    Time time1;
    auto* derived = new Derived;
    time1.start();

    for(int i=0; i<1000000; ++i)
    {
        derived->calculate_inl();
    }
    time1.end();
}
int main()
{
    test();
    test2();
    test3();
}