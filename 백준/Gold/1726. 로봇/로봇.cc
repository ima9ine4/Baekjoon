#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;
vector<vector<int>> map;
int dx[5] = {0, 0, 0, 1, -1};  // 1: 동(오른쪽), 2: 서(왼쪽), 3: 남(아래), 4: 북(위)
int dy[5] = {0, 1, -1, 0, 0};


int n,m;
int sx, sy, sd, ex, ey, ed;

int bfs(){
    queue<tuple<int,int,int,int>> q; // {x,y,dir,count}
    vector<vector<vector<bool>>> visited(n, vector<vector<bool>>(m, vector<bool>(4, false)));
    q.push({sx,sy,sd,0});
    visited[sx][sy][sd] = true;
    int ret = 0;

    while(!q.empty()){
        int x = get<0>(q.front());
        int y = get<1>(q.front());
        int dir = get<2>(q.front());
        int cnt = get<3>(q.front());
        q.pop();
        
        if(x==ex && y==ey && dir==ed){ // 목적지 도달
            ret = cnt;
            break;
        }

        for(int i=1;i<=3;i++){ // 현재 방향으로 1,2,3 칸 이동
            int nx = x + dx[dir] * i;
            int ny = y + dy[dir] * i;

            if(nx<0 || nx >=n || ny<0 || ny>=m || map[nx][ny]==1) break; //벽이거나 1이면 바로 break;

            if(!visited[nx][ny][dir]){ //방문하지 않았으면
                visited[nx][ny][dir] = true; // 방문체크
                q.push({nx,ny,dir,cnt+1}); // q에 추가
            }

        }
        
        int left_dir, right_dir; // 방향 전환
        if(dir==1){
            left_dir = 4;
            right_dir = 3;
        }else if(dir==2){
            left_dir = 3;
            right_dir = 4;
        }
        else if(dir==3){
            left_dir = 1;
            right_dir = 2;
        }else{ // dir==4
            left_dir = 2;
            right_dir = 1;
        }

        if(!visited[x][y][left_dir]){ // 왼쪽으로 회전
            visited[x][y][left_dir] = true;
            q.push({x,y,left_dir,cnt+1});

        }
        if(!visited[x][y][right_dir]){ // 오른쪽으로 회전
            visited[x][y][right_dir] = true;
            q.push({x,y,right_dir,cnt+1});
        }
    }
    return ret;
}

int main(){
    cin>>n>>m;
    map = vector<vector<int>>(n,vector<int>(m,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>map[i][j];
        }
    }
    cin>>sx>>sy>>sd>>ex>>ey>>ed;
    sx--; sy--; ex--; ey--;
    int ans = bfs();
    cout<<ans<<endl;
}