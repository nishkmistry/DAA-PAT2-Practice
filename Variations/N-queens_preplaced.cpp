#include <iostream>
#include <vector>
#include <string>

using namespace std;

void printBoard(const vector<string>& board) {
    for (const string& row : board) {
        cout << row << "\n";
    }
    cout << "\n";
}

void solveNQueens(int row, int n, vector<string>& board, 
                  vector<bool>& col, vector<bool>& leftDiag, vector<bool>& rightDiag, 
                  int& solutionCount) {
    if (row == n) {
        solutionCount++;
        cout << "Solution " << solutionCount << ":\n";
        printBoard(board);
        return;
    }

    for (int c = 0; c < n; c++) {
        if (!col[c] && !leftDiag[row + c] && !rightDiag[row - c + n - 1]) {
            
            board[row][c] = 'Q';
            col[c] = true;
            leftDiag[row + c] = true;
            rightDiag[row - c + n - 1] = true;

            solveNQueens(row + 1, n, board, col, leftDiag, rightDiag, solutionCount);

            board[row][c] = '.';
            col[c] = false;
            leftDiag[row + c] = false;
            rightDiag[row - c + n - 1] = false;
        }
    }
}

int main() {
    int n = 4; // Use 4x4 for cleaner output
    
    vector<string> board(n, string(n, '.'));
    vector<bool> col(n, false);
    vector<bool> leftDiag(2 * n - 1, false);
    vector<bool> rightDiag(2 * n - 1, false);
    
    // --- VARIATION LOGIC ---
    // Rule: The first queen is glued to row 0, column 2.
    int fixedRow = 0;
    int fixedCol = 2;
    
    board[fixedRow][fixedCol] = 'Q';
    col[fixedCol] = true;
    leftDiag[fixedRow + fixedCol] = true;
    rightDiag[fixedRow - fixedCol + n - 1] = true;

    int solutionCount = 0;
    
    cout << "--- N-Queens: Pre-Placed Queen at (0,2) ---\n";
    
    // Start recursion at row 1, skipping the fixed row 0
    solveNQueens(1, n, board, col, leftDiag, rightDiag, solutionCount);
    
    if (solutionCount == 0) cout << "No solutions exist.\n";

    return 0;
}