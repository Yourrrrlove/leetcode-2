#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> partitionLabels(string s) {
        if(s.size() <= 1) return {(int) s.size()};
        vector<int> result;
        int hash[26] = {0};
        for(int i = 0; i < s.size(); ++i) hash[s[i] - 'a'] = i; // 记录每个字母最后出现的位置
        int left = 0, right = 0;
        for(int i = 0; i < s.size(); ++i){
            right = max(right, hash[s[i] - 'a']); //求字母s[i]出现的最远位置
            if(i == right){ //如果找到字符最远出现位置下标和当前下标相等了，则找到了分割点
                result.push_back(right - left + 1); //划分出来的片段长度
                left = right + 1; //下一个片段的起始位置
            }
        }
        return result;
    }
};

int main(){
    string s = "ababcbacadefegdehijhklij";
    Solution solution;
    vector<int> result = solution.partitionLabels(s);
    for(int i = 0; i < result.size(); ++i) cout << result[i] << " ";
    return 0;
}