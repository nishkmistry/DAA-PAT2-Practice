#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;
void lcs(string x, string y){
    int m = x.length();
    int n = y.length();
    vector<vector<int>> l(m+1, vector(n+1, 0));
    for(int i=1; i<=m; i++){
        for(int j=1; j<=n; j++){
            if(x[i-1]==y[j-1]){
                l[i][j] = l[i-1][j-1] + 1;
            }
            else{
                l[i][j] = max(l[i-1][j], l[i][j-1]);
            }
        }
    }
    cout << "Length of lcs is : " << l[m][n] << endl;
    int idx = l[m][n];
    string lcsstr(idx, '\0');
    int i = m, j=n;
    while(i > 0 && j > 0){
        if(x[i-1] == y[j-1]){
            lcsstr[idx-1] = x[i-1];
            i--;
            j--;
            idx--;
        }
        else if(l[i-1][j] > l[i][j-1]){
            i--;
        }
        else{
            j--;
        }
    }
    cout << "The lcs : " << lcsstr << endl;
    return;
}
int main(){
    lcs("AGGTAB", "GXTXAYB");
    return 0;
}