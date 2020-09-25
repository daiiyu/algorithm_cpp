#include <iostream>
#include <vector>
#include <cassert>
#include <functional>
using namespace std;
template <typename T=int, typename Comp = less<T>>
vector<int> merge(vector<T>&left_unsorted, vector<T> right_unsorted, Comp comp= less<T>())
{


    vector<int> mergedArr(left_unsorted.size()+right_unsorted.size());
    int pos = 0;
    int left = 0;
    int left_end = left_unsorted.size();
    int right = 0;
    int right_end = right_unsorted.size();
    while(left!=left_end && right!=right_end)
    {
        if( comp(left_unsorted[left], right_unsorted[right])) {
            mergedArr[pos] = left_unsorted[left];
            left++;
        }else{
            mergedArr[pos] = right_unsorted[right];
            right++;
        }
        pos++;

    }
    if(left != left_end){
        while(left != left_end){
            mergedArr[pos] = left_unsorted[left];
            left++;
            pos++;
        }
    }else{
        while(right!=right_end){
            mergedArr[pos] = right_unsorted[right];
            right++;
            pos++;
        }
    }
    return mergedArr;
}

template<typename  Container>
void print(Container con){
    for(auto e: con){
        cout<<e<<endl;
    }
}
vector<int> mergeSort(vector<int>& unsorted, int left, int right)
{
    if(right == left)
        return vector<int>{};

    int mid = (left+right)/2;
    auto left_merged = std::move(mergeSort(unsorted, left, mid));
    auto right_merged = std::move(mergeSort(unsorted, mid+1, right));
    return merge(left_merged, right_merged);
}
vector<int> mergeSort(vector<int>&& unsorted, int left, int right)
{
    return mergeSort(unsorted, left, right);
}
int main() {
    vector<int> unsorted {9,8,7,6,5,4,3,2,1};
    print(mergeSort(unsorted, 0, unsorted.size()));
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
