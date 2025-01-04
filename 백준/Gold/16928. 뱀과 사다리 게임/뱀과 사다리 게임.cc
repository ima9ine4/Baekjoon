// 16928 뱀과 사다리 게임
// https://www.acmicpc.net/problem/16928

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(){
    int n,m; cin>>n>>m;
    vector<int> map(101, 0);
    vector<int> visited(101,-1);
    queue<int> q;

    int x,y;
    for(int i=0;i<n;i++){
        cin>>x>>y;
        map[x] = y;
    }
    for(int i=0;i<m;i++){
        cin>>x>>y;
        map[x] = y;
    }

    q.push(1);
    visited[1] = 0;
    int now;
    while(!q.empty()){
        now = q.front();
        q.pop();
        if(now == 100){
            cout<<visited[now]<<endl;
            break;
        }

        for(int i=1;i<=6;i++){
            int next = now + i;
            
            if(next>100) continue;

            // 다음 위치에 사다리나 뱀이 있으면 이동
            if(map[next] != 0){
                next = map[next];
            }

            // 다음 위치가 방문하지 않은 칸이면
            if(visited[next] == -1){
                q.push(next);
                visited[next] = visited[now] + 1;
            }
        }
    }
}