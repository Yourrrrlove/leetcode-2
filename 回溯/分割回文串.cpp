#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
private:
    vector<string> path;
    vector<vector<string>> result;
    //判断s中[start, end]是否为回文串
    bool isPalindrome(const string &s, int start, int end){
        if(start > end) return false;
        while(start <= end){
            if(s[start] != s[end]) return false;
            ++start;
            --end;
        }
        return true;
    }

    void backtracking(string &s, int startIndex){
        if(startIndex >= s.size()){ //起始位置到了s的末尾，说明已经找到了一组分割方案
            result.push_back(path);
            return;
        }
        for(int i = startIndex; i < s.size(); ++i){
            //path中只包含回文串
            if(isPalindrome(s, startIndex, i)) path.push_back(s.substr(startIndex, i - startIndex + 1));
            else continue;
            backtracking(s, i + 1); //搜索i+1为起始位置的子串
            path.pop_back(); //回溯
        }
    }
public:
    vector<vector<string>> partition(string s) {
        if(s.size() == 0) return {};
        if(s.size() == 1) return {{s}};
        path.clear();
        result.clear();
        backtracking(s, 0);
        return result;
    }
};

int main(){
    Solution s;
    vector<vector<string>> ret = s.partition("aab");
    for(auto &v : ret){
        for(auto &str : v){
            cout << str << " ";
        }
        cout << endl;
    }
    return 0;
}