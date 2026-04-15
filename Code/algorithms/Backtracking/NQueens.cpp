#include <bits/stdc++.h>
using namespace std;

/*
N-Queens Problem (Backtracking)

```
Goal:
-----
Place N queens on an N x N chessboard such that
no two queens attack each other.


🔴 Core Mistakes :

1. Unnecessary Checks ❌
     • lower rows (currRow --> n-1)
     • left lower diagonal
     • right lower diagonal
   - This is WRONG because:
     → We place queens row by row (top → bottom)
     → So future rows are EMPTY
     → No need to check them

   ✅ Correct approach:
     • Check only rows ABOVE current row
     • Check only:
         - same column ↑
         - upper-left diagonal ↖
         - upper-right diagonal ↗


2. Wrong Board Representation ❌
   - I used: vector<vector<string>>
   - Problem:
     → board[r][c] becomes a STRING, not a char

   ✅ Better options:
     (a) vector<vector<char>> → works but needs conversion later while pushing into ans 2D vector (Extra work)
     (b) vector<string> → BEST choice

    Board Initialization:
     vector<string> board(n, '.');         ❌ WRONG → creates n rows, each of length 1 (".")
     vector<string> board(n, string(n,'.')); ✅ CORRECT → creates n x n board ("....")


   Why vector<string>?
     → Each row = string
     → Each column = character in that string
     → board[r][c] directly gives char
     → Matches required output format
     → No extra conversion needed


🔁 Backtracking Idea:
   -------------------
   For each row:
     → Try placing queen in every column
     → If safe:
         place queen
         recurse to next row
         remove queen (backtrack)


⏱️ Time Complexity:
   ----------------
   Roughly O(N^N)

   Explanation:
   - For each row → N choices
   - Total rows = N
   → Total possibilities ≈ N^N

   Note:
   - We also check safety (O(N)) multiple times
   - So total ≈ O(N^N * N)
   - But we simplify it to O(N^N)

## 💾 Space Complexity:

Auxiliary Space: O(N)

* Recursion stack depth = N (one call per row)

Board Storage:

* O(N²)
* Because we store an N x N chessboard

Answer Storage:

* O(K × N²)
* K = number of valid solutions
* Each solution stores a full N x N board

---

Total Space: O(N) + O(N²) + O(K x N²) = O(K x N²) 



💯 Key Takeaway:
   -------------
   - Always think:
     "What parts of the board are already filled?"
   - Only check those — not the entire board
```

*/


// Checks if placing a queen at (row, col) is safe
bool isSafe(int row, int col, vector<string> &board, int n) {

    // Check same column (only rows above)
    for (int r = 0; r < row; r++) {
        if (board[r][col] == 'Q') return false;
    }

    // Check upper-left diagonal ↖
    int r = row, c = col;
    while (r >= 0 && c >= 0) {
        if (board[r][c] == 'Q') return false;
        r--; c--;
    }

    // Check upper-right diagonal ↗
    r = row, c = col;
    while (r >= 0 && c < n) {
        if (board[r][c] == 'Q') return false;
        r--; c++;
    }

    return true;
}



// Backtracking function to place queens row by row
void NQueens(int R, vector<string> &board, int n, vector<vector<string>> &ans) {

    //Base Case: all queens placed
    if (R == n) {
        ans.push_back(board);
        return;
    }

    // Try placing queen in every column of current row
    for (int c = 0; c < n; c++) {

        if (isSafe(R, c, board, n)) {

            //Place queen
            board[R][c] = 'Q';

            //Recurse for next row
            NQueens(R + 1, board, n, ans);

            //Backtrack
            board[R][c] = '.';
        }
    }
}


int main() {

    int n;
    cout << "Enter n: ";
    cin >> n;

    //Proper board initialization
    vector<string> board(n, string(n, '.'));

    vector<vector<string>> ans;

    NQueens(0, board, n, ans);

    // Print solutions
    cout << "\nAll possible solutions:\n";

    for (const auto &solution : ans) {
        cout << "----------------\n";
        for (const auto &row : solution) {
            cout << row << endl;
        }
    }

    return 0;
}