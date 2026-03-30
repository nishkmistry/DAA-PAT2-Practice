#include<string>
#include<algorithm>
#include<vector>
#include<iostream>
using namespace std;
void lcs(string X, string Y){
    int m = X.length(), n = Y.length();
    vector<vector<int>> l(m+1, vector<int>(n+1, 0)); // dp matrix m+1 x n+1
    for(int i=1; i<=m; i++){
        for(int j=1; j<n+1; j++){
            if(X[i-1] == Y[j-1]){
                //match : increase diagonal element by 1
                l[i][j] = l[i-1][j-1] + 1;
            }
            else{
                //mismatch : take max out of the top and left element
                l[i][j] = max(l[i-1][j], l[i][j-1]);
            }
        }
    }
    cout << "Length of LCS is: " << l[m][n] << endl;
    int index = l[m][n];
    string lcsstr(index, '\0');
    int i = m, j=n;
    while(i>0 && j>0){
        if(X[i-1] == Y[j-1]){
            lcsstr[index-1] = X[i-1];
            i--;
            j--;
            index--;
        }
        else if(l[i-1][j] > l[i][j-1]){
            i--; //Move up
        }
        else{
            j--; //Move left
        }
    }
    cout << "The lowest common subsequence is: " << lcsstr << endl;
    return;
}
int main(){
    lcs("AGGTAB", "GXTXAYB");
    return 0;
}