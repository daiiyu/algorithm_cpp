#include <vector>
#include <iostream>
#include <algorithm>

using namespace  std;
int partition(vector<int>&nums, int left, int right)
{
    int pivot = nums[left];

    while(left< right){
        while(left < right&& nums[right]>= pivot)
            right--;
        nums[left] = nums[right];
        while(left< right&& nums[left] <= pivot)
            left++;
        nums[right] = nums[left];
    }
    nums[left] = pivot;
    return left;
}
int partition2(vector<int>&nums, int left, int right)
{

    int pivot = nums[left];
    while(left<right){

        while(left<right && nums[right] >= pivot)
            right --;

        nums[left ] = nums[right];
        while(left<right && nums[right] <=pivot)
            left++;
        nums[right] = nums[left];
    }
    nums[left] = pivot;
    return left;
}

void quickSort(vector<int>&nums, int left, int right)
{
    if(left >=right)
        return;
    int pos = partition2(nums, left, right);
    quickSort(nums, left , pos-1);
    quickSort(nums, pos+1, right);
}

void myMerge(vector<int>& left, vector<int>& right,vector<int>& bars)
{
    int nL= left.size();
    int nR = right.size();
    int i=0;
    int j=0;
    int k=0;

    while(j<nL&&k<nR){
        if(left[j]<right[k]){
            bars[i] = left[j];
            j++;
        }else{
            bars[i] = right[k];
            k++;
        }
        i++;
    }
    while(j<nL){
        bars[i] = left[j];
        ++j;
        ++i;
    }
    while(k<nR){
        bars[i] = right[k];
        ++k;
        ++i;
    }
}
void mergeSort(vector<int>&bars)
{
    if(bars.size()<=1)
        return ;

    int mid =bars.size() /2;
    vector<int> left(mid);
    vector<int> right(bars.size()- mid);
    for(std::size_t j=0; j<mid; ++j)
    {
        left[j] = bars[j];
    }
    for(size_t j=0; j < (bars.size()- mid); ++j)
    {
        right[j] = bars[mid+j];
    }
    mergeSort(left);
    mergeSort(right);
    //myMerge(left, right, bars);
    std::merge(left.begin(), left.end(), right.begin(), right.end(), bars.begin());
}

#include <mutex>
#include <atomic>
class Singleton
{
public:
    static  Singleton* getInstance(){
        if(instance.load() == nullptr) {
            std::lock_guard<std::mutex> lockGuard(mutex);
            instance.store(new Singleton());;
        }
            return instance.load();
    }

    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;
    Singleton& operator=(const Singleton&&) = delete;

private:
    Singleton(){}
    static std::atomic<Singleton*> instance;
    static std::mutex mutex;
};

class Singleton2
{
    static Singleton2 instance;

};
template<typename Container>
void bubbleSort(Container& nums)
{
    for(int i=0; i<nums.size(); ++i) {
        int keepGoing = false;
        int end = nums.size() - i;
        for (int j=0; (j+1) < end; j++){
            if(nums[j] > nums[j+1]){
                swap(nums[j], nums[j+1]);
                keepGoing=true;
            }
        }
        if(keepGoing == false)
            return;
    }



}

int main()
{
    vector<int> nums{6, 4,3,2,8,9,2};
    //quickSort(nums, 0, nums.size()-1);
    //mergeSort(nums);
    bubbleSort(nums);
    for(auto n: nums)
    {
        cout<<n<<" ";
    }
    cout<<endl;
}