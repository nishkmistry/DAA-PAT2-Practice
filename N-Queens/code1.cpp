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
    for(int i=r-1, j=c-1; i>=0 && j>=0 ; i--, j--){
        if(board[i][j]){
            return false;
        }
    }
    for(int i=r-1, j=c+1; i>=0 && j<N ; i--, j++){
        if(board[i][j]){
            return false;
        }
    }
    return true;
}
bool solveNQueen(int row){
    if(row == N){
        return true;
    }
    for(int col = 0; col < N; col++){
        if(isSafe(row, col)){
            board[row][col] = 1;
            if(solveNQueen(row+1)){
                return true;
            }
        board[row][col] = 0;
        }
    }
    return false;
}
int main(){
    cout << "Enter number of queens: ";
    cin >> N;
    if(solveNQueen(0)){
        cout << "\nSolution:\n";
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
    }
    else{
        cout << "No solution exists";
    }
    return 0;
}