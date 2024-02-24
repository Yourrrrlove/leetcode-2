#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int monotoneIncreasingDigits(int n){
        string s = std::to_string(n); // 将数字转换为字符串,方便遍历和操作
        //flag及以后的位置需要设为9
        /*
        flag初始化为s.size()，是为了防止误触发第二个for循环
        如果n本身就是单调递增的，如果flag初始化为0,则会跳过第一个for循环，直接执行第二个for循环，将所有位都设为9,导致错误答案
        */
        int flag = s.size();
        for(int i = s.size() - 1; i > 0; --i){
            if(s[i - 1] > s[i]){
                flag = i; //前一位大于当前位，所以当前位及以后都要设为9，用flag记录下位置
                --s[i - 1]; //前一位减1
            }
        }
        for(int i = flag; i < s.size(); ++i) s[i] = '9'; //将flag及以后的位置设为9
        return std::stoi(s); //将字符串转换为数字
    }
};