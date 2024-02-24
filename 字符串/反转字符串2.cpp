#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    string reverseStr(string s, int k) {
        //从字符串开头算起，每计数至 2k 个字符，就反转这 2k 字符中的前 k 个字符,处理完这2k个字符后，再从下一个 2k 字符开始继续同样的操作，所以 i += 2*k
        for(int i = 0; i < s.size(); i += 2*k){
            //if(s.size() - i >= 2*k) reverse(s.begin() + i, s.begin() + i + k); //如果剩余字符大于等于2k个，说明还可以计数至 2k 个字符，反转这2k个字符中的前k个字符
            //else if(s.size() - i >= k) reverse(s.begin() + i, s.begin() + i + k); //如果剩余字符小于 2k 但大于或等于 k 个，则反转前 k 个字符，其余字符保持原样
            //由于上面两if语句的判断条件区间合起来为 s.size()-i>=k且执行相同的操作，所以可以合并为一句：
            if(s.size() - i >= k) reverse(s.begin() + i, s.begin() + i + k);
            else reverse(s.begin() + i, s.end()); //如果剩余字符少于 k 个，则将剩余字符全部反转。
        }
        return s;
    }
};