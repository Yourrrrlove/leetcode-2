#include<iostream>
#include <vector>
using namespace std;

class Solution{
public:
    int removeDuplicates(vector<int> &nums){
        int slow = 0;
        for(int fast = 1; fast < nums.size(); fast++){
            if(nums[slow] != nums[fast]) nums[++slow] = nums[fast];
        }
        return slow + 1;
    }
};

int main(){
    Solution s;
    vector<int> vec{0,0,1,1,1,2,2,3,3,4};
    cout << s.removeDuplicates(vec) << endl;
    return 0;
}