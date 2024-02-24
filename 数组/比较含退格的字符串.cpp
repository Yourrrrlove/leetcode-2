#include <iostream>
#include <string>
#include <stack>
using namespace std;
class Solution{
private:
    string Compare(string &s){
        string result;
        for(char &ch : s){
            if(ch != '#') result.push_back(ch);
            else{
                if(!result.empty()) result.pop_back();
            }
        }
        return result;
    }
public:
    bool backspaceCompare(string s, string t){
        return Compare(s) == Compare(t);
    }
};

int main(){
    Solution s;
    string s1 = "ab#c", s2 = "ad#c";
    cout << std::boolalpha << s.backspaceCompare(s1, s2) << std::noboolalpha << endl;
    return 0;
}