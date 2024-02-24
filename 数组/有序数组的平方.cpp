#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    vector<int> sortedSquares(vector<int> &nums){
        int n = nums.size() - 1;
        vector<int> res(n + 1, 0);
        for(int i = 0, j = n, pos = n; i <= j && pos >= 0; --pos){
            if(nums[i]*nums[i] > nums[j]*nums[j]){
                res[pos] = nums[i]*nums[i];
                ++i;
            }
            else{
                res[pos] = nums[j]*nums[j];
                --j;
            }
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<int> vec{-4,-1,0,3,10};
    vector<int> result = s.sortedSquares(vec);
    for(auto i : result) cout << i << " ";
    return 0;
}