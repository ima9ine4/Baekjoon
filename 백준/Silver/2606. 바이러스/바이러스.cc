#include <iostream>
#include <cstring>
using namespace std;

#define MAX_V 101

int V,E;
int graph[MAX_V][MAX_V];
bool visited[MAX_V];
int cnt = 0;

void dfss(int v){
    visited[v] = true;
    
    for(int next=1;next<=V;next++){
        if(!visited[next] && graph[v][next]){
            cnt++;
            dfss(next);
        }
    }
}

int main() {
    cin>>V>>E;
    memset(visited,0,sizeof(visited));
    memset(graph, 0, sizeof(graph));
    for(int i=0;i<E;i++) {
        int a,b; cin>>a>>b;
        graph[a][b] = graph[b][a] = 1; 
    }
    dfss(1);
    cout<<cnt<<endl;
    return 0;
}