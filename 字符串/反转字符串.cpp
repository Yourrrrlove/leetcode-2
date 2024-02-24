#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        int left = 0, right = s.size() - 1; //双指针
        while(left <= right){
            if(s[left] != s[right]) swap(s[left], s[right]); //相等的话不用交换
            ++left;
            --right;
        }
    }
};

int main(){
    Solution s;
    vector<char> str{'h', 'e', 'l', 'l', 'o'};
    s.reverseString(str);
    for(const auto &ch : str) cout << ch << " ";
    cout << endl;
    return 0;
}