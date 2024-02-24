#include <iostream>
#include <string>
using namespace std;

class Solution{
public:
    string replaceNumber(string &s){
        //使用额外空间
        // string ret;
        // for(const auto &x : s){
        //     if(x - 48 >= 0 && x - 48 <= 9) ret += "number"; //x是数字
        //     else ret += x; //x是字母
        // }
        // return ret;


        //不使用额外空间，原地替换
        int count = 0;
        //统计s中数字的个数
        for(const auto &x : s){
            if(x - 48 >= 0 && x - 48 <= 9) ++count;
        }
        //双指针
        int oldEnd = s.size() - 1; //oldEnd指向原字符串的末尾
        s.resize(s.size() + 5*count); //将s的长度扩大至 把所有数字替换成number后 的长度
        int newEnd = s.size() - 1; //newEnd指向新字符串的末尾
        while(oldEnd >= 0 && newEnd >= 0){
            if(s[oldEnd] >= '0' && s[oldEnd] <= '9'){
                s[newEnd] = 'r';
                s[newEnd - 1] = 'e';
                s[newEnd - 2] = 'b';
                s[newEnd - 3] = 'm';
                s[newEnd - 4] = 'u';
                s[newEnd - 5] = 'n';
                --oldEnd;
                newEnd -= 6;
            }
            if(s[oldEnd] >= 'a' && s[oldEnd] <= 'z'){
                s[newEnd] = s[oldEnd];
                --newEnd;
                --oldEnd;
            }
        }
        return s;
    }
};

int main(){
    Solution sol;
    string s;
    cin >> s;
    cout << sol.replaceNumber(s) << endl;
    return 0;
}