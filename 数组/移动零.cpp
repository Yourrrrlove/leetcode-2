#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    void moveZeroes(vector<int> &nums){
        int slow = 0;
        for(int fast = 0; fast < nums.size(); fast++){
            if(nums[fast] != 0) nums[slow++] = nums[fast];
        }
        for(; slow < nums.size(); ++slow){
            nums[slow] = 0;
        }
    }
};

int main(){
    Solution s;
    vector<int> vec{0,1,0,3,12};
    s.moveZeroes(vec);
    for(auto i : vec) cout << i << " ";
    return 0;
}