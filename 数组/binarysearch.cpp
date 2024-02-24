#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    int search(vector<int>& nums, int target){
        int left = 0, right = nums.size() - 1, mid = left + (right - left) / 2;
        while(left <= right){
            if(nums[mid] < target) left = mid + 1;
            else if(nums[mid] > target) right = mid - 1;
            else return mid;
            mid = left + (right - left) / 2;
        }
        return -1;
    }
};

int main(){
    Solution s;
    vector<int> nums{-1,0,3,5,9,12};
    int target = 10;
    cout << s.search(nums, target) << endl;
    //cout << "hello" << endl;
    return 0;
}