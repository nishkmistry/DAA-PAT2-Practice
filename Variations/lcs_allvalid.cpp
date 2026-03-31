#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>

using namespace std;

// Recursive backtrack to find all paths
void findAllLCS(string X, string Y, int i, int j, vector<vector<int>>& L, string current, set<string>& allLCS) {
    // Base case: Reached the end of either string
    if (i == 0 || j == 0) {
        reverse(current.begin(), current.end());
        allLCS.insert(current);
        return;
    }

    // If characters match, add to current string and move diagonally
    if (X[i - 1] == Y[j - 1]) {
        findAllLCS(X, Y, i - 1, j - 1, L, current + X[i - 1], allLCS);
    } else {
        // Mismatch: Branch out if both directions have the same max value
        if (L[i - 1][j] >= L[i][j - 1]) {
            findAllLCS(X, Y, i - 1, j, L, current, allLCS); // Move Up
        }
        if (L[i][j - 1] >= L[i - 1][j]) {
            findAllLCS(X, Y, i, j - 1, L, current, allLCS); // Move Left
        }
    }
}

void processAllLCS(string X, string Y) {
    int m = X.length();
    int n = Y.length();
    vector<vector<int>> L(m + 1, vector<int>(n + 1, 0));

    // Build standard DP table
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (X[i - 1] == Y[j - 1]) {
                L[i][j] = L[i - 1][j - 1] + 1;
            } else {
                L[i][j] = max(L[i - 1][j], L[i][j - 1]);
            }
        }
    }

    cout << "Max Length is: " << L[m][n] << "\n";

    set<string> allLCS; // Set ensures unique sequences
    findAllLCS(X, Y, m, n, L, "", allLCS);

    cout << "All Longest Common Subsequences:\n";
    for (const string& str : allLCS) {
        cout << str << "\n";
    }
}

int main() {
    string S1 = "ABCBDAB";
    string S2 = "BDCABA";
    
    cout << "--- Print ALL Longest Common Subsequences ---\n";
    processAllLCS(S1, S2);
    
    return 0;
}