#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if(nums.size() <= 1) return nums.size();
        /*
        result用来记录峰，谷的个数,也就是摆动序列的长度
        result初始化为1（默认最右面有一个峰值），因为一个摆动至少有两个元素，例如[1,3]，只有一个摆动，但应该返回2
        preDiff = nums[i] - nums[i - 1]，用来记录前一个差值
        curDiff = nums[i + 1] - nums[i]，用来记录当前差值
        */
        int preDiff = 0, curDiff = 0, result = 1;
        //curDiff = nums[i + 1] - nums[i],所以i < nums.size() - 1
        for(int i = 0; i < nums.size() - 1; ++i){
            curDiff = nums[i + 1] - nums[i];
            //如果curDiff和preDiff异号，说明是峰或者谷
            /*preDiff=0情况：
            [1,2,2,2,1],遍历到最后一个2时,preDiff=0,curDiff<0;
            或[2,1,1,1,2],遍历到最后一个1时,preDiff=0,curDiff>0
            */
            if(preDiff >=0 && curDiff < 0 || preDiff <= 0 && curDiff > 0){
                ++result;
                /*
                只有当curDiff和preDiff异号时，才更新preDiff
                例如[1,2,2,2,3]，除了默认的最右面是一个峰，就没有其他峰或谷了：
                刚开始i指向元素1,preDiff=0,curDiff=1,更新preDiff=1
                此后curDiff>=0,preDiff=1,都不是峰或谷，所以不更新preDiff，result也不会更新。
                */
               /*
               如果把preDiff = curDiff写在if外面，那么preDiff会实时更新。
               还是以[1,2,2,2,3]为例，遍历到最后一个2时，preDiff实时更新为0,curDiff=1,result会+1，但实际上最后一个2不是峰也不是谷。
                preDiff = curDiff;
               */
                preDiff = curDiff;
            }
        }
        return result;
    }
};

int main(){
    Solution sol;
    vector<int> nums{1,2,2,2,3,4};
    cout << sol.wiggleMaxLength(nums) << endl;
    return 0;
}