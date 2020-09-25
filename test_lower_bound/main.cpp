#include <iostream>
#include <vector>
#include <algorithm>
using namespace  std;
int main() {
    //vector<int> arr{0,1,2,3,4,5,5,5,5,5,6};
    vector<int> arr{6,5,5,5,5,5,4,3,2,1,0};
    auto left = lower_bound(arr.begin(), arr.end(), 5, [](int x,int y)
    {
        return x>y;
    });

    cout<<*(left-1)<<endl;
    cout<<distance(arr.begin(), arr.end())<<endl;
    cout<< (arr.begin()+11 < (arr.begin()+5))<<endl;
    return 0;
}
