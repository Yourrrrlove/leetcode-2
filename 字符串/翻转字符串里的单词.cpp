#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    void reverse(string &s, int start, int end){
        for(int i = start, j = end; i < j; ++i, --j){
            swap(s[i], s[j]);  //首位对调，实现s的翻转
        }
    }
    //去除多余空格：前导空格、尾随空格或者单词间的多个空格
    void removeExtraSpaces(string &s){
        int slow = 0;
        for(int i = 0; i < s.size(); ++i){
            if(s[i] != ' '){  //遇到非空格才处理，即先删除所有空格
                if(slow != 0) s[slow++] = ' ';  //手动在单词间添加空格
                while(i < s.size() && s[i] != ' '){ //把后面的单词搬到前面来
                    s[slow++] = s[i++];
                }
            }
        }
        s.resize(slow);
    }
    string reverseWords(string s) {
        removeExtraSpaces(s);  //先去除多余空格
        reverse(s, 0, s.size() - 1);  //翻转整个字符串
        int start = 0;
        for(int i = 0; i <= s.size(); ++i){
            if(i == s.size() || s[i] == ' '){ //到达空格位置或字符串的末尾，说明找到单词的结尾
                reverse(s, start, i - 1);  //翻转单词
                start = i + 1;  //更新start为下一个单词的起始位置
            }
        }
        return s;
    }
};

int main(){
    Solution s;
    string str;
    cout << "Please input a string: " << endl;
    /*
    cin >> str;
    cin默认以空格作为分隔符，所以只会读取到第一个空格之前的内容作为一个单词。如果您想读取整行输入作为一个字符串，可以使用getline(cin, str)来替代cin >> str。这样可以读取包含空格的整行输入。
    */
    getline(cin, str);
    cout << s.reverseWords(str) << endl;
    return 0;
}