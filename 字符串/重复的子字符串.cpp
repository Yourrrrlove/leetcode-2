#include <iostream>
#include <string>
using namespace std;

//暴力解法
// class Solution {
// public:
//     bool repeatedSubstringPattern(string s) {
        
//         for(int len = 1; len <= s.size() / 2; ++len){  //1 <= 重复子串的长度 <= s.size() / 2 (至少重复两次)
//             if(s.size() % len == 0){  //如果s.size() % len == 0, 说明s可以被len整除, 说明s可能由长度为len的子串重复组成
//                 int repeatCount = s.size() / len;  //重复的次数
//                 string sub_str = s.substr(0, len);  //重复的子串
//                 string newstr;  //重复的子串重复repeatCount次后的字符串
//                 while(repeatCount--) newstr += sub_str;  //重构字符串
//                 if(newstr == s) return true;   //如果sub_str重复repeatCount次后构成的字符串与原字符串相等, 说明s是由子串sub_str重复组成的
//             }
//         }
//         return false;
//     }
// };

//移动匹配

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        string str = s + s;
        //为了避免在 s+s 中搜索到原来的 s，要掐头去尾，这样 s 在 s + s 中就只出现一次
        str.erase(str.begin());  //删除第一个字符
        str.erase(str.end() - 1);  //删除最后一个字符
        if(str.find(s) != std::string::npos) return true; //如果s在str中出现过, 说明s是由子串重复组成的。注意：string没有str.end()成员函数
        return false;
    }
};

int main(){
    Solution s;
    string str;
    getline(cin, str);
    cout << boolalpha << s.repeatedSubstringPattern(str) << noboolalpha << endl;
    return 0;
}