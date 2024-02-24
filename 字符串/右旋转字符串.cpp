#include <iostream>
#include <string>
using namespace std;

class Solution{
private:
    //反转s中闭区间[start, end]的元素
    void reverse(string &s, int start, int end){
        while(start <= end){
            swap(s[start], s[end]);
            ++start;
            --end;
        }
    }
public:
    void rotateRightString(string &s, int k){
        reverse(s, 0, s.size() - 1); //先整体反转
        reverse(s, 0, k - 1);  //再反转前k个字符
        reverse(s, k, s.size() - 1);  //最后反转剩下的字符
    }
};

int main(){
    Solution s;
    int k;
    string str;
    cin >> k;
    cin.get();  //吸收换行符
    getline(cin, str);
    s.rotateRightString(str, k);
    cout << str;
    return 0;
}