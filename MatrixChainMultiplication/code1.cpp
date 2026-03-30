#include <iostream>
#include <vector>
#include <climits>

using namespace std;

// Recursive function to print the optimal parenthesization using the bracket table
void printParenthesis(int i, int j, const vector<vector<int>>& bracket, char& matrixName) {
    // Base case: If there is only one matrix left, print its name
    if (i == j) {
        cout << matrixName++;
        return;
    }
    
    cout << "(";
    // Recursively put brackets around the left sub-problem
    printParenthesis(i, bracket[i][j], bracket, matrixName);
    
    // Recursively put brackets around the right sub-problem
    printParenthesis(bracket[i][j] + 1, j, bracket, matrixName);
    cout << ")";
}

void matrixChainOrder(const vector<int>& p) {
    int n = p.size();
    
    // m[i][j] stores minimum scalar multiplications needed to compute A[i]...A[j]
    // 0th row and 0th column are unused for simplicity (1-based indexing for matrices)
    vector<vector<int>> m(n, vector<int>(n, 0));
    
    // bracket[i][j] stores the optimal split point 'k' to achieve m[i][j]
    vector<vector<int>> bracket(n, vector<int>(n, 0));

    // L is the chain length. L=2 means multiplying 2 matrices, L=3 means 3, etc.
    for (int L = 2; L < n; L++) {
        for (int i = 1; i < n - L + 1; i++) {
            int j = i + L - 1;
            m[i][j] = INT_MAX; // Initialize to infinity
            
            // Try every possible split point 'k' between i and j-1
            for (int k = i; k <= j - 1; k++) {
                // Cost = cost of left chain + cost of right chain + cost to multiply them
                int q = m[i][k] + m[k + 1][j] + (p[i - 1] * p[k] * p[j]);
                
                if (q < m[i][j]) {
                    m[i][j] = q;       // Update minimum cost
                    bracket[i][j] = k; // Store the split point that gave this minimum
                }
            }
        }
    }

    cout << "Minimum number of multiplications: " << m[1][n - 1] << "\n";
    
    char matrixName = 'A';
    cout << "Optimal Parenthesization: ";
    printParenthesis(1, n - 1, bracket, matrixName);
    cout << "\n";
}

int main() {
    // Represents matrices: A1(40x20), A2(20x30), A3(30x10), A4(10x30)
    vector<int> dimensions = {40, 20, 30, 10, 30}; 
    
    matrixChainOrder(dimensions);
    
    return 0;
}