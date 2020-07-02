#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template <typename T>
class IsOdd
{
    public:
    IsOdd(){}
    inline bool operator()(const T &data)
    {
        return  ( (data & 0x1) == 1 );
    }
};

template <typename T, typename Comp> 
void divide(vector<T>& array, Comp comp)
{
    int low = 0;
    int high = array.size() -1;
    while(low < high)
    {

        //find even
        while(low < high && comp(array[low])) ++low;

        while(low < high && !comp(array[high])) -- high;

        swap(array[low], array[high]);
    }

    
}

int main()
{
    vector<int> array;
    for(int i =0; i<100; ++i)
    {
        array.push_back(i);
    }
    divide<int> (array, IsOdd<int>());

    for(auto& x: array)
    {
        cout<<x<<"\t";
    }
    cout<<endl;
    
}