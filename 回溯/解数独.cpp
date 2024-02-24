#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    bool isValid(int row, int col, char val, vector<vector<char>> &board){
        for(int i = 0; i < 9; ++i){ //检查同一列是否有相同val
            if(board[i][col] == val) return false;
        }
        for(int j = 0; j < 9; ++j){ //检查同一行是否有相同val
            if(board[row][j] == val) return false;
        }
        //检查3x3方格内是否有相同val
        //board是9x9的，所以每个3x3方格的起始行列索引是row/3*3和col/3*3
        //例如row从0到2,row / 3 * 3 都是0，所以board的0——2行都是第一个3x3方格
        //col同理
        int startRow = row / 3 * 3, startCol = col / 3 * 3;
        for(int i = startRow; i < startRow + 3; ++i){
            for(int j = startCol; j < startCol + 3; ++j){
                if(board[i][j] == val) return false;
            }
        }
        return true;
    }

    //只要找到一种解法就立刻结束搜索，所以使用bool返回值
    bool backtracking(vector<vector<char>>& board){
        for(int i = 0; i < board.size(); ++i){ //遍历board的每一行
            for(int j = 0; j < board[0].size(); ++j){ //遍历board的每一列
                if(board[i][j] == '.'){  //找到需要填数字的空白格
                    for(char k = '1'; k <= '9'; ++k){ //尝试填入数字1-9
                        if(isValid(i, j, k, board)){  //如果数字k可以填入空白格
                            board[i][j] = k;  //填入数字k
                            if(backtracking(board)) return true; //找到一种解法立刻结束
                            board[i][j] = '.';  //回溯
                        }
                    }
                    return false; //1-9都无法填入空白格，无解
                }
            }
        }
        return true; //遍历完board的所有空白格，所有空白格都填入了数字，得到一种解法
    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        backtracking(board);
    }
};

int main(){
    Solution s;
    vector<vector<char>> board = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
    };
    s.solveSudoku(board);
    for(auto &vec : board){
        for(auto &ch : vec){
            cout << ch << " ";
        }
        cout << endl;
    }
    return 0;
}