#include<iostream>
#include<vector>
#include<string>


using namespace std;


class Solution {
public:
    bool isSafe(int i, int j, int n){
        return (i >= 0 && j >= 0 && i < n && j < n);
    }

    vector<vector<char>> update_board(vector<vector<char>> board, int i, int j){
        int n = board.size();
        for(int k = 0; k < n; k++){
            if(board[i][k] == '.') board[i][k] = 'x';
        }
        for(int k = 0; k < n; k++){
            if(board[k][j] == '.') board[k][j] = 'x';
        }
        int k = i, l = j;
        while(isSafe(k, l, n)){
            if(board[k][l] == '.') board[k][l] = 'x';
            k++; l++;
        }
        k = i, l = j;
        while(isSafe(k, l, n)){
            if(board[k][l] == '.') board[k][l] = 'x';
            k--; l--;
        }
        k = i, l = j;
        while(isSafe(k, l, n)){
            if(board[k][l] == '.') board[k][l] = 'x';
            k--; l++;
        }
        k = i, l = j;
        while(isSafe(k, l, n)){
            if(board[k][l] == '.') board[k][l] = 'x';
            k++; l--;
        }
        return board;
    }

    void init_board(vector<vector<char>>& board){
        int n = board.size();
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                board[i][j] = '.';
            }
        }
    }

    vector<string> make_board(vector<vector<char>> board){
        vector<string> res;
        string str;
        int n = board.size();
        for(int i = 0; i < n; i++){
            str.clear();
            for(int j = 0; j < n; j++){
                str.push_back((board[i][j] != 'Q' ? '.' : 'Q'));
            }
            res.push_back(str);
        }
        return res;
    }

    void dfs(vector<vector<string>>& res, vector<vector<char>> board, int i, int n){
        if(i == n){
            res.push_back(make_board(board));
            return;
        }

        int j = 0;
        while(j < n){
            if(board[i][j] != 'x'){
                board[i][j] = 'Q';
                dfs(res, update_board(board, i, j), i + 1, n);
                board[i][j] = '.';
            }
            j++;
        }
    }

    void printBoards(vector<vector<string>> res){
        int n = res.size();
        int boardSize = res[0].size();

        for(int i = 0; i < n; i++){
            cout << "\n==========BOARD_" << i + 1 << "==========\n\n";
            for(int j = 0; j < boardSize; j++){
                for(int k = 0; k < boardSize; k++){
                    cout << res[i][j][k] << " ";
                }
                cout << "\n";
            }
        }

    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<char>> board(n, vector<char>(n));
        init_board(board);
        vector<vector<string>> res;

        dfs(res, board, 0, n);
        return res;
    }
};


int main(){

    int n;
    cin >> n;


    Solution sol;
    vector<vector<string>> res = sol.solveNQueens(n);
    sol.printBoards(res);


}
