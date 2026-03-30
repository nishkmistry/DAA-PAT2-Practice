#include<iostream>
#include<climits>
#include<vector>
using namespace std;
void printParenthesis(int i, int j,const vector<vector<int>> &bracket, char &matrixname){
    if(i == j){
        cout << matrixname++;
        return;
    }
    else{
        cout << "(";
        printParenthesis(i, bracket[i][j], bracket, matrixname);
        printParenthesis(bracket[i][j]+1, j, bracket, matrixname);
        cout << ")";
    }
}
void matrixChainOrder(const vector<int> &o){
    int n = o.size();
    vector<vector<int>> m(n, vector<int>(n, 0)), bracket(n, vector<int>(n, 0));
    for(int l = 2; l<n; l++){
        for(int i=1; i<n+1-l; i++){
            int j = i+l-1;
            m[i][j] = INT_MAX;
            for(int k=i; k<=j-1; k++){
                int q = m[i][k] + m[k+1][j] + o[i-1] * o[k] * o[j];
                if(q < m[i][j]){
                    m[i][j] = q;
                    bracket[i][j] = k;
                }
            }
        }
    }
    cout << "Minimum number of multiplication: " << m[1][n-1] << endl;
    char matrixName = 'A';
    cout << "Optimal Parenthesization: ";
    printParenthesis(1, n-1, bracket, matrixName);
    cout << endl;
    return;
}
int main(){
    vector<int> d = {40, 20, 30, 10, 30};
    matrixChainOrder(d);
    return 0;
}