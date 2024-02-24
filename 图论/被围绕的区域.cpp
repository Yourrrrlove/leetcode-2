#include <iostream>
#include <vector>
using namespace std;

class Solution{
private:
    int dire[2][4] = {{-1,1,0,0},{0,0,-1,1}};
    //dfs负责将board[x][y]所在的岛屿(此岛屿全为O)全部置为W
    void dfs(vector<vector<char>>& board, int x, int y){
        int row = board.size(), col = board[0].size();
        board[x][y] = 'W';
        for(int i = 0; i < 4; ++i){
            int next_x = x + dire[0][i], next_y = y + dire[1][i];
            if(next_x < 0 || next_x >= row || next_y < 0 || next_y >= col || board[next_x][next_y] == 'X') continue;
            dfs(board, next_x, next_y);
        }
    }
public:
    void solve(vector<vector<char>>& board){
        int row = board.size(), col = board[0].size();
        /*
        把最上下左右四条边上及其相连的O全部置为W
        此时剩下的O就是被围绕的O
        再遍历一遍board，把O置为X，把W置为O
        */
        for(int i = 0; i < row; ++i){ //最左边一列
            if(board[i][0] == 'O') dfs(board, i, 0);
        }
        for(int i = 0; i < row; ++i){ //最右边一列
            if(board[i][col - 1] == 'O') dfs(board, i, col - 1);
        }
        for(int j = 0; j < col; ++j){ //最上边一行 
            if(board[0][j] == 'O') dfs(board, 0, j);
        }
        for(int j = 0; j < col; ++j){ //最下边一行
            if(board[row - 1][j] == 'O') dfs(board, row - 1, j);
        }
        //遍历一遍board，把O置为X，把W置为O
        for(int i = 0; i < row; ++i){
            for(int j = 0; j < col; ++j){
                if(board[i][j] == 'O') board[i][j] = 'X';
                else if(board[i][j] == 'W') board[i][j] = 'O';
            }
        }
    }
};

int main(){
    vector<vector<char>> board = {
        {'X','X','X','X'},
        {'X','O','O','X'},
        {'X','X','O','X'},
        {'X','O','X','X'}
    };
    Solution s;
    s.solve(board);
    for(int i = 0; i < board.size(); ++i){
        for(int j = 0; j < board[0].size(); ++j){
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}