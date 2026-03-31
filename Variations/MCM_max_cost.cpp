#include <iostream>
#include <vector>
#include <climits>

using namespace std;

void maxMatrixChainOrder(const vector<int>& p) {
    int n = p.size();
    
    // m[i][j] stores MAXIMUM scalar multiplications
    vector<vector<int>> m(n, vector<int>(n, 0));
    
    for (int L = 2; L < n; L++) {
        for (int i = 1; i < n - L + 1; i++) {
            int j = i + L - 1;
            m[i][j] = INT_MIN; // Initialize to negative infinity
            
            for (int k = i; k <= j - 1; k++) {
                int q = m[i][k] + m[k + 1][j] + (p[i - 1] * p[k] * p[j]);
                
                // Look for the maximum cost
                if (q > m[i][j]) {
                    m[i][j] = q;
                }
            }
        }
    }

    cout << "Maximum number of multiplications: " << m[1][n - 1] << "\n";
}

int main() {
    // Dimensions for A1(40x20), A2(20x30), A3(30x10), A4(10x30)
    vector<int> dimensions = {40, 20, 30, 10, 30}; 
    
    cout << "--- Maximum Matrix Chain Multiplication ---\n";
    maxMatrixChainOrder(dimensions);
    
    return 0;
}