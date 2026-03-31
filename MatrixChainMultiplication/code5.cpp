#include<iostream>
#include<climits>
#include<vector>
using namespace std;
void pp(int i, int j, const vector<vector<int>>&b, char &c){
    if(i==j){
        cout << c++;
    }
    else{
        cout << "(";
        pp(i, b[i][j], b, c);
        pp(b[i][j]+1, j, b, c);
        cout << ")";
    }
    return;
}
void mcm(const vector<int>& p){
    int n = p.size();
    vector<vector<int>> m(n, vector<int>(n, 0)), b(n, vector<int>(n, 0));
    for(int l=2; l<n; l++){
        for(int i=1; i<n+1-l; i++){
            int j = i+l-1;
            m[i][j] = INT_MAX;
            for(int k=i; k<=j-1; k++){
                int q = m[i][k] + m[k+1][j] + p[i-1] * p[k] * p[j];
                if(q<m[i][j]){
                    m[i][j] = q;
                    b[i][j] = k;
                }
            }
        }
    }
    cout << "Minimum number of multipliation: " << m[1][n-1] << endl;
    cout << "Optimal Parenthesization : ";
    char c = 'A';
    pp(1, n-1, b, c);
    cout << endl;
    return;
}
int main(){
    vector<int> d = {40, 20, 30, 10, 30};
    mcm(d);
    return 0;
}