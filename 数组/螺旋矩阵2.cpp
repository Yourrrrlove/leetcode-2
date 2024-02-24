#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    vector<vector<int>> generateMatrix(int n){
        vector<vector<int>> result(n, vector<int>(n, 0));
        int startx = 0, starty = 0;
        int loop = n / 2;  //需要循环的圈数
        int mid = n / 2;  //矩阵中心坐标，n为奇数时需要单独处理中心
        int count = 1; //用来填充result[i][j]的值，初始化为1
        int offset = 1; //需要控制每个边的遍历长度，每转一圈，右边界收缩一位
        int i, j;
        while(loop--){
            i = startx, j = starty;
            //从左到右填充每圈的上行，左闭右开，例如n=4，则只填充第一行的1,2,3，留下4
            for(; j < n - offset; ++j){
                result[i][j] = count++;
            }
            //从上到下填充每圈的右列，左闭右开，例如n=4，则只填充最右列的4，5，6，留下7
            for(; i < n - offset; ++i){
                result[i][j] = count++;
            }
            //从右到左填充每圈的下行，左闭右开，例如n=4，则只填充最下行的7，8，9，留下10
            for(; j > starty; --j){  //或者j > offset - 1
                result[i][j] = count++;
            }
            //从下到上填充每圈的左列，左闭右开，例如n=4，则只填充最左列的10，11，12
            for(; i > startx; --i){  //或者i > offset - 1
                result[i][j] = count++;
            }

            startx++, starty++;
            offset++;
        }
        if(n % 2 == 1) result[mid][mid] = count;
        return result;
    }
};

int main(){
    Solution s;
    int n = 4;
    vector<vector<int>> res = s.generateMatrix(n);
    for(const auto &row : res){
        for(const auto &col : row){
            cout << col << " ";
        }
        cout << endl;
    }
    return 0;
}

