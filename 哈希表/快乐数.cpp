#include <iostream>
#include <unordered_set>
using namespace std;

/*
输入：n = 19
输出：true
解释：
12 + 92 = 82
82 + 22 = 68
62 + 82 = 100
12 + 02 + 02 = 1
*/
class Solution {
private:
    int calculateSum(int n){
        int sum = 0;
        while(n){
            sum += (n % 10) * (n % 10);  // 计算n的每一位的平方和
            n /= 10;
        }
        return sum;
    }
public:
    bool isHappy(int n) {
        unordered_set<int> set;
        while(1){
            int sum = calculateSum(n);
            if(sum == 1) return true;  // 如果求和过程中sum变为1，则说明n是快乐数
            if(set.find(sum) != set.end()) return false;  // 如果求和过程中某个中间值sum重复出现了，则说明无限循环了，n不是快乐数
            else set.insert(sum);  // 如果sum没有出现过，则将sum加入到set中
            n = sum;  // 将n更新为sum，继续求和
        }
        return false;
    }
};