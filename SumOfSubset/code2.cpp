#include<iostream>
#include<vector>
#include<numeric>
#include<algorithm>
using namespace std;
void printSubset(const vector<int>& subset){
    cout << "{";
    for(int i : subset){
        cout << " " << i << " ";
    }
    cout << "}" << endl;
}
void sumOfSubsets(int index, int currentSum, int remainingSum, const vector<int>& w, int M, vector<int>& subset, bool& found){
    subset.push_back(w[index]);
    if(currentSum + w[index] == M){
        printSubset(subset);
        found = true;
    }else if(((index + 1) < w.size()) && ((currentSum + w[index] + w[index + 1]) <= M)){
        sumOfSubsets(index+1, currentSum + w[index], remainingSum - w[index], w, M, subset, found);
    }
    subset.pop_back();
    if(((index+1) < w.size()) && ((currentSum + remainingSum - w[index]) >= M) && (currentSum + w[index+1] <= M)){
        sumOfSubsets(index+1, currentSum, remainingSum-w[index], w, M, subset, found);
    }
}
void solveSubsetSum(vector<int>& weights, int target){
    sort(weights.begin(), weights.end());
    int totalSum = accumulate(weights.begin(), weights.end(), 0);
    if(totalSum < target || weights[0] > target){
        cout << "No subset is possible.";
        return;
    }
    vector<int> subset;
    bool found = false;
    cout << "Subset summing to target are : " << endl;
    sumOfSubsets(0, 0, totalSum, weights, target, subset, found);
    if(!found){
        cout << "No subset is possible." <<endl;
    }
}
int main(){
    vector<int> weight = {10, 7, 5, 18, 12, 20, 15};
    int target = 35;
    solveSubsetSum(weight, target);
    return 0;
}