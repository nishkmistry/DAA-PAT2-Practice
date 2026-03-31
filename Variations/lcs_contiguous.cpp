#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void longestCommonSubstring(string X, string Y) {
    int m = X.length();
    int n = Y.length();

    vector<vector<int>> L(m + 1, vector<int>(n + 1, 0));
    
    int maxLength = 0; 
    int endIndex = 0;  

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (X[i - 1] == Y[j - 1]) {
                L[i][j] = L[i - 1][j - 1] + 1;
                
                // Track the maximum value found anywhere in the table
                if (L[i][j] > maxLength) {
                    maxLength = L[i][j];
                    endIndex = i - 1; 
                }
            } else {
                // Reset to 0 if the contiguous streak breaks
                L[i][j] = 0; 
            }
        }
    }

    cout << "Length of Longest Common Substring: " << maxLength << "\n";
    if (maxLength > 0) {
        cout << "The Substring is: " << X.substr(endIndex - maxLength + 1, maxLength) << "\n";
    }
}

int main() {
    string S1 = "VelloreInstitute";
    string S2 = "ChennaiInstituteCampus";
    
    cout << "--- Longest Common Substring ---\n";
    longestCommonSubstring(S1, S2);
    
    return 0;
}