#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution{
private:
    vector<vector<string>> result;
    bool isValid(int n, int row, int col, vector<string> &chessBoard){
        for(int i = 0; i < row; ++i){ //检查同一列是否有皇后
            if(chessBoard[i][col] == 'Q') return false;
        }
        for(int j = 0; j < col; ++j){ //检查同一行是否有皇后
            if(chessBoard[row][j] == 'Q') return false;
        }
        //检查左上角对角线是否有皇后
        for(int i = row - 1, j = col - 1; i >= 0 && j >= 0; --i, --j){
            if(chessBoard[i][j] == 'Q') return false;
        }
        //检查右上角对角线是否有皇后
        for(int i = row - 1, j = col + 1; i >= 0 && j < n; --i, ++j){
            if(chessBoard[i][j] == 'Q') return false;
        }
        return true;
    }

    void backtracking(int n, int row, vector<string> &chessBoard){
        if(row == n){ //到达nxn棋盘的最后一行
            result.push_back(chessBoard);
            return;
        }
        //遍历棋盘某行的每一列
        for(int col = 0; col < n; ++col){
            if(isValid(n, row, col, chessBoard)){
                chessBoard[row][col] = 'Q'; //在这一行尝试放置皇后
                backtracking(n, row + 1, chessBoard); //在下一行寻找放置皇后的位置
                chessBoard[row][col] = '.'; //回溯
            }
        }
    }

public:
    vector<vector<string>> solveNQueens(int n){
        result.clear();
        vector<string> chessBoard(n, string(n, '.')); //初始化nxn的棋盘
        backtracking(n, 0, chessBoard);
        return result;
    }
};

int main(){
    Solution s;
    auto ret = s.solveNQueens(4);
    for(auto &vec : ret){
        for(auto &str : vec){
            cout << str << endl;
        }
        cout << endl;
    }
    return 0;
}