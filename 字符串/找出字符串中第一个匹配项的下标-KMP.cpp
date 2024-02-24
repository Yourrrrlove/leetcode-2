#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.size() > haystack.size()) return -1;
        for(int i = 0; i < haystack.size(); i++){
            for(int j = 0; j < needle.size() && i + j < haystack.size(); j++){
                if(needle[j] != haystack[i + j]) break;
                if(j == needle.size() - 1) return i;
            }
        }
        return -1;
    }
};

int main(){
    Solution s;
    string haystack = "sadbutsad", needle = "saddd";
    cout << s.strStr(haystack, needle) << endl;
    return 0;
}