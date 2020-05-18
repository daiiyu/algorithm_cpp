#include <vector>
#include <iostream>
#include <algorithm>
#include <cstdlib>
using namespace std;

class Solution {
    
public:
    bool Find(int target, vector<vector<int> > array) {
        
        for( const auto &line : array){
            if(target >= (*line.begin()) && target <=(*(line.end()-1))){
                bool result = binary_search(line.begin(), line.end(), target);
                if(result)
                    return true;
            }
        }
        return false;
    }
    
   
};

int main(int argc, char ** argv)
{
    if(argc < 2)
    {
        cout<<"at least 2 arguments"<<endl;
        exit(-1);
    }

    Solution solution;
    vector<int> array{0,1,2,3,4,5,6,7};
    vector<vector<int>> array2 {{{1,2,8,9}, 
                                {2,4,9,12},
                                {4,7,10,13},
                                {6,8,11,15}}};
    int result = solution.Find(atoi(argv[1]), array2);

    cout<<result<<endl;

}