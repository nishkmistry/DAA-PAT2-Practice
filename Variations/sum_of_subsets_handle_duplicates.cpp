#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

void printSubset(const vector<int>& subset) {
    cout << "{ ";
    for (int val : subset) {
        cout << val << " ";
    }
    cout << "}\n";
}

void uniqueSubsetSum(int index, int currentSum, int remainingSum, 
                     const vector<int>& w, int M, vector<int>& subset, bool& found) {
    
    // 1. INCLUDE the current element
    subset.push_back(w[index]);
    
    if (currentSum + w[index] == M) {
        printSubset(subset);
        found = true;
    } else if (index + 1 < w.size() && currentSum + w[index] + w[index + 1] <= M) {
        uniqueSubsetSum(index + 1, currentSum + w[index], remainingSum - w[index], 
                        w, M, subset, found);
    }
    
    // BACKTRACK
    subset.pop_back();

    // VARIATION LOGIC: Skip adjacent duplicate elements in the array
    while (index + 1 < w.size() && w[index] == w[index + 1]) {
        index++; 
        remainingSum -= w[index]; // Adjust remaining sum pool
    }

    // 2. EXCLUDE the current element
    if (index + 1 < w.size() && currentSum + remainingSum - w[index] >= M 
        && currentSum + w[index + 1] <= M) {
        uniqueSubsetSum(index + 1, currentSum, remainingSum - w[index], 
                        w, M, subset, found);
    }
}

int main() {
    // Array with duplicates
    vector<int> weights = {10, 10, 5, 20, 15, 5}; 
    int target = 25;
    
    // Sorting is mandatory for the duplicate logic to work
    sort(weights.begin(), weights.end());
    
    int totalSum = accumulate(weights.begin(), weights.end(), 0);
    vector<int> subset;
    bool found = false;
    
    cout << "--- Sum of Subsets: Unique Solutions Only ---\n";
    
    if (totalSum >= target && weights[0] <= target) {
        uniqueSubsetSum(0, 0, totalSum, weights, target, subset, found);
    }
    
    if (!found) cout << "No valid subsets found.\n";
    
    return 0;
}