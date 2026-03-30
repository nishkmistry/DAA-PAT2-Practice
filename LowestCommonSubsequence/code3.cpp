#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
void lcs(string x, string y){
    int m = x.length(), n = y.length();
    vector<vector<int>> l(m+1, vector<int>(n+1, 0));
    for(int i=1; i<=m; i++){
        for(int j=1; j<=n; j++){
            if(x[i-1] == y[j-1]){
                l[i][j] = l[i-1][j-1] + 1;
            }
            else{
                l[i][j] = max(l[i-1][j], l[i][j-1]);
            }
        }
    }
    cout << "Length of LCS is : " << l[m][n] << endl;
    int index = l[m][n];
    string lcsstr(index, '\0');
    int i = m, j = n;
    while(i > 0 && j > 0){
        if(x[i-1] == y[j-1]){
            lcsstr[index-1] = x[i-1];
            i--;
            j--;
            index--;
        }
        else if(l[i-1][j] > l[i][j-1]){
            i--;
        }
        else{
            j--;
        }
    }
    cout << "LCS : " << lcsstr << endl;
    return;
}
int main(){
    lcs("AGGTAB", "GXTXAYB");
    return 0;
}