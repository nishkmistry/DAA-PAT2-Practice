#include<iostream>
using namespace std;
#define M 100
int board[M][M];
int N;
bool isSafe(int r, int c){
    for(int i=0; i<r; i++){
        if(board[i][c]){
            return false;
        }
    }
    for(int i=r-1, j=c-1; i>=0 && j>=0; i--, j--){
        if(board[i][j]){
            return false;
        }
    }
    for(int i=r-1, j=c+1; i>=0 && j<N; i--, j++){
        if(board[i][j]){
            return false;
        }
    }
    return true;
}
bool solveNQueen(int r){
    if(r == N){
        return true;
    }
    else{
        for(int c = 0; c<N; c++){
            if(isSafe(r,c)){
                board[r][c] = 1;
                if(solveNQueen(r+1)){
                    return true;
                }
                board[r][c] = 0;
            }
        }
    }
    return false;
}
int main(){
    cout << "Number of Q: ";
    cin >> N;
    if(solveNQueen(0)){
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
    }
    else{
        cout << "No solution exist." << endl;
    }
    return 0;
}