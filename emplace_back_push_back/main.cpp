#include <iostream>


#include <vector>
using namespace  std;

class Base
{
public:
    Base(){
        cout<<"default constructed"<<endl;
    }
    Base(int a){
        cout<<"argument constructed"<<endl;
    }
    Base(const Base& base ){
        cout<<"copy constructed"<<endl;
    }
    //*
    Base(const Base&& base){
        cout<<"move constructed"<<endl;
    }
    ~Base()
    {
        cout<<"destruction"<<endl;
    }
     //*/
};
int main() {
    vector<Base> bases;
    bases.push_back(1);
    cout<<"__________________"<<endl;
    bases.emplace_back(1);
    cout<<"__________________"<<endl;
    return 0;
}
