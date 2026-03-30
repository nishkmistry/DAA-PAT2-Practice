#include<iostream>
#include<vector>
using namespace std;
bool isSafe(int v, const vector<vector<int>>& graph, const vector<int>& color, int c){
    for(int i=0; i<graph.size(); i++){
        if(graph[v][i] == 1 && c == color[i]){
            return false;
        }
    }
    return true;
}
bool graphColouringUtil(const vector<vector<int>>& graph, int m, vector<int>& color, int v){
    if(v == graph.size()){
        return true;
    }
    for(int c = 1; c <= m; c++){
        if(isSafe(v, graph, color, c)){
            color[v] = c;
            if(graphColouringUtil(graph, m, color, v+1)){
                return true;
            }
            color[v] = 0;
        }
    }
    return false;
}
void solveGraphColoring(const vector<vector<int>>& graph, int m){
    int V = graph.size();
    vector<int> color(V, 0);
    if(!graphColouringUtil(graph, m, color, 0)){
        cout << "Solution does not exist for " << m << "colors." << endl;
    }
    cout << "Solution exists! The assigned colors are: " << endl;
    for (int i=0; i<V; i++){
        cout << "Vertex" << i << "--> Color " << color[i] << endl;
    }
}
int main(){
    vector<vector<int>> graph = {
        {0, 1, 0, 1},
        {1, 0, 1, 1},
        {0, 1, 0, 1},
        {1, 1, 1, 0}
    };
    int m = 3;
    solveGraphColoring(graph, m);
    return 0;
}