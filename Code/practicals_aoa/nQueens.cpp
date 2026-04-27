#include <iostream>
#include <vector>
using namespace std;

bool isSafe(int row, int col, vector<string> &board, int n){
    // same col
    for(int r = 0; r < n; r++){
        if(board[r][col] == 'Q') return false;
    }

    // upper left diagonal
    int r = row, c = col;
    while(r >= 0 && c >= 0){
        if(board[r][c] == 'Q') return false;
        r--;
        c--;
    }

    // upper right diagonal
    r = row, c = col;
    while(r >= 0 && c < n){
        if(board[r][c] == 'Q') return false;
        r--;
        c++;
    }
    return true;
}

void nQueens(int R, vector<string> &board, int n, vector<vector<string>> &ans){
    if(R == n) {
        ans.push_back(board);
        return;
    }

    // try placing
    for(int c = 0; c < n; c++){
        if(isSafe(R, c, board, n)){
            board[R][c] = 'Q';

            // next
            nQueens(R + 1, board, n, ans);

            // backtrack
            board[R][c] = '.';
        }
    }
}

int main(){
    int n;
    cout << "Enter the num of queens: ";
    cin >> n;

    if(n == 2 || n == 3){
        cout << "No Solutions";
        return 0;
    }

    vector<string> board(n, string(n, '.'));

    vector<vector<string>> ans;

    nQueens(0, board, n, ans);

    cout << "\n All possible solutions: \n";

    for(int i = 0; i < n; i++){
        cout << "------------------\n"; 
        for(int j = 0; j < n; j++){
            cout << ans[i][j] << endl;
        }
    }

    return 0;
}