#include <iostream>
#include <string>
#include <climits>
#include <unordered_map>
using namespace std;

// class Solution{
// private:
//     bool check(string t, unordered_map<char, int> &count){
//         for(char ch : t){
//             if(count.count(ch) <= 0) return false;
//         }
//         return true;
//     }
// public:
//     string minWindow(string s, string t){
//         if(t.size() > s.size()) return "";
//         int left = 0, length = INT_MAX;
//         string result;
//         unordered_map<char, int> count;
//         for(int right = 0; right < s.size(); right++){
//             ++count[s[right]];
//             while(check(t, count)){
//                 length = min(length, right - left + 1);
//                 if(right - left + 1 < length) result = s.substr(left, length);
//                 if(--count[s[left]] < 0) break;
//                 ++left;
//             }
//         }
//         return result;
//     }
// };

// int main(){
//     Solution s;
//     string s1 = "ADOBECODEBANC", s2 = "ABC";
//     cout << s.minWindow(s1, s2) << endl;
//     return 0;
// }

// class Solution{
// private:
//     bool check(unordered_map<char, int> &ori, unordered_map<char, int> &count){
//         for(const auto &p : ori){
//             if(count[p.first] < p.second) return false;
//         }
//         return true;
//     }
// public:
//     string minWindow(string s, string t){
//         if(t.size() > s.size()) return "";
//         int left = 0, right = -1, length = INT_MAX, res_left = -1, res_right = -1;
//         unordered_map<char, int> ori, count;
//         for(const auto &ch : t) ++ori[ch];
//         while(right < (int) s.size()){ //这里right一开始为-1，而s.size()为无符号整型，负数int型和无符号整型比较时，负数int会转为很大的无符号整型，所以必须把s.size()强转为int型
//             if(ori.find(s[++right]) != ori.end()) ++count[s[right]];
//             while(check(ori, count) && left <= right){
//                 if(right - left + 1 < length){
//                     length = right - left + 1;
//                     res_left = left;
//                 }
//                 if(ori.find(s[left]) != ori.end()) --count[s[left]];
//                 ++left;
//             }
//         }
//         return res_left == -1 ? "" : s.substr(res_left, length);
//     }
// };

// int main(){
//     Solution s;
//     string s1 = "ADOBECODEBANC", s2 = "ABC";
//     cout << s.minWindow(s1, s2) << endl;
//     return 0;
// }

class Solution{
public:
    unordered_map<char, int> ori, count;
    //check函数用来检查s中的区间[left, right]的子串是否包含 t 的所有字符
    bool check(){
        for(const auto &p : ori){
            if(count[p.first] < p.second) return false;
        }
        return true;
    }
    string minWindow(string s, string t){
        if(t.size() > s.size()) return ""; //如果t比s还长，那么s中肯定不包含t
        //left表示滑动窗口的左边界，right表示滑动窗口的右边界，length表示最小子串的长度，res_left表示最小子串的左边界，res_right表示最小子串的右边界
        int left = 0, length = INT_MAX, res_left = -1, res_right = -1;
        for(const auto &ch : t) ++ori[ch];//统计 t 中每个字符的数量
        for(int right = 0; right < s.size(); ++right){
            if(ori.find(s[right]) != ori.end()) ++count[s[right]];//如果 t 中也有字符 s[right]，那么count中 s[right] 的数量+1
            while(check() && left <= right){ //如果s的从left到right的当前子串包含t的所有字符，就在满足题意的前提下尝试缩减子串长度
                if(right - left + 1 < length){  
                    length = right - left + 1;//更新满足题意的子串长度length
                    res_left = left;  //更新满足题意的子串的左侧起始位置res_left
                }
                if(ori.find(s[left]) != ori.end()) --count[s[left]];//前面只在t 中也有字符 s[right]时才++count[s[right]]，所以这里也只在t 中也有字符 s[left]时才--count[s[left]]
                //对于不在t中的字符s[left]，没有必要--count[s[left]]
                ++left; //缩减子串长度
            }
        }
        return res_left == -1 ? "" : s.substr(res_left, length); //如果最后res_left没有被改变，说明s中不包含t
    }
};

int main(){
    Solution s;
    string s1 = "ADOBECODEBANC", s2 = "ABC";
    cout << s.minWindow(s1, s2) << endl;
    return 0;
}