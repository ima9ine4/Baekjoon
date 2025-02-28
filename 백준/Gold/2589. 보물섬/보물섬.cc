#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int n,m;
vector<vector<char>> map;
int dx[4] = {0, 0, -1, 1}; //상 하 좌 우
int dy[4] = {1, -1, 0, 0};

int bfs(int i, int j){
    vector<vector<int>> visited(n,vector<int>(m,0));
    queue<pair<int,int>> q;
    visited[i][j] = 1;
    q.push({i,j});
    int maxLength = 0;

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(int i=0;i<4;i++){
            int nextX = x + dx[i];
            int nextY = y + dy[i];

            if(nextX >= 0 && nextX < n && nextY >= 0 && nextY < m && visited[nextX][nextY] == 0 && map[nextX][nextY] == 'L' ){
                // map 안에 위치하고 방문하지 않은 육지
                visited[nextX][nextY] = visited[x][y] + 1;
                q.push({nextX, nextY});
                maxLength = max(maxLength, visited[nextX][nextY]);
            }
        }
    }
    return maxLength;
}

int main(){
    cin>>n>>m;
    map = vector<vector<char>>(n,vector<char>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>map[i][j];
        }
    }
    int ans = 0;
    int cnt = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(map[i][j]=='L'){ //육지를 만나면
                cnt++;
                int tmp = bfs(i,j); // (i,j) 출발으로 가능한 최장거리
                if(ans<tmp) ans = tmp;
            }
        }
    }
    ans -= 1;
    cout<<ans<<endl;
}