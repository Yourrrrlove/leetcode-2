#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
private:
    int pointnum = 0; //记录'.'的个数
    vector<string> result;
    bool isValid(string &s, int start, int end){
        if(start > end) return false;
        if(end - start >= 1 && s[start] == '0') return false; //s[start, end]为0开头的多位数字
        int num = 0;
        for(int i = start; i <= end; ++i){
            if(s[i] < '0' || s[i] > '9') return false;  //包含非数字的情况
            num = num * 10 + (s[i] - '0');
            if(num > 255 || num < 0) return false;  //大于255或<0的情况
        }
        return true;
    }

    void backtracking(string &s, int startIndex){
        if(pointnum == 3){
            //判断第四段子字符串是否合法，如果合法就放进result中
            //因此这里判断的是第四段子字符串是不包含'.'的，所以isValid函数不需要判断位置i是否为'.'
            if(isValid(s, startIndex, s.size() - 1)) result.push_back(s);
            return;
        }

        for(int i = startIndex; i < s.size(); ++i){
            if(isValid(s, startIndex, i)){
                s.insert(s.begin() + i + 1, '.'); //在i后面的位置插入一个'.'
                ++pointnum;
                backtracking(s, i + 2);
                //回溯
                --pointnum;
                s.erase(s.begin() + i + 1); //删除之前插入的'.'
            }
            else break;
        }
    }
public:
    vector<string> restoreIpAddresses(string s) {
        if(s.size() < 4 || s.size() > 12) return {}; //剪枝
        pointnum = 0;
        result.clear();
        backtracking(s, 0);
        return result;
    }
};

int main(){
    Solution s;
    vector<string> ret = s.restoreIpAddresses("25525511135");
    for(auto &str : ret){
        cout << str << " ";
    }
    cout << endl;
    return 0;
}