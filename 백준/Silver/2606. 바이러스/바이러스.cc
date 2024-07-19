#include <iostream>
#include <cstring>
using namespace std;

#define MAX_N 101
int V,E;
int cnt = 0;
int graph[MAX_N][MAX_N];
bool visited[MAX_N];

void dfs(int node){
    visited[node] = true;
    for(int next = 1; next <= V; next++){
        if(!visited[next] && graph[node][next]){
            cnt += 1;
            dfs(next);
        }
    }
}

int main() {
    cin>>V>>E;
    memset(visited, 0, sizeof(visited));
    memset(graph, 0, sizeof(graph));
    for(int i=0;i<E;i++){
        int a,b;
        cin >> a >> b;
        graph[a][b] = graph[b][a] = 1;
    }
    dfs(1);
    cout << cnt << endl;
    return 0;
}
