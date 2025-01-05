#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int n;
queue<pair<int,int>> q;
vector<vector<int>> map;
vector<vector<int>> visited;

void move(int x, int y, int a, int b){
    // 체스판을 벗어났거나 이미 방문한 곳이라면
    if( x+a < 0 || x+a > n-1 || y+b <0 || y+b > n-1 || visited[x+a][y+b] == 1){
        return;
    }else{
        // 방문했음을 기록, 다음 위치를 q에 넣고, 방문 횟수 업데이트
        visited[x+a][y+b] = 1;
        q.push({x+a,y+b});
        map[x+a][y+b] = map[x][y] + 1;
    }
}

int main(){
    cin>>n;
    map.resize(n,vector<int> (n,0));
    visited.resize(n,vector<int>(n,0));
    int x_start, y_start, x_end, y_end;
    cin>>x_start>>y_start>>x_end>>y_end;

    q.push({x_start,y_start});
    map[x_start][y_start] = 0;
    int cantmove = 1;

    vector<pair<int,int>> direction = {{-2,-1}, {-2,1}, {0,-2}, {0,2}, {2,-1}, {2,1}};
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        if( x == x_end && y == y_end){
            cout<<map[x][y]<<endl;
            cantmove = 0;
            break;
        }
        for(int i=0;i<6;i++){
            move(x, y, direction[i].first, direction[i].second);
        }
    }
    // 이동할 수 없는 경우
    if(cantmove){
        cout<<-1<<endl;
    }
}