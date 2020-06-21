#include <memory>
#include <iostream>

using namespace std;

class B;
struct A{
    shared_ptr<B> b;
};
struct B{
    shared_ptr<A> a;
};
int main()
{
    shared_ptr<A> pa;
    shared_ptr<B> pb;
    {
        pa = make_shared<A>();
        pb = make_shared<B>();
        pa->b = pb;
        cout<<pa.use_count()<<endl;
        cout<<pb.use_count()<<endl;

    }
    cout<<pa.use_count()<<endl;
    cout<<pb.use_count()<<endl;

    }
