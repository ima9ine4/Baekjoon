#include <iostream>
#include <vector>
#include <queue>
#define MAX 64
using namespace std;
int N,M;
int map[9][9];
int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};

queue<pair<int, int>> virus;
vector<pair<int, int>> safe;

int BFS(){
    queue<pair<int,int>> q = virus;
    int cnt = 0;
    int visited[9][9] = {0};
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        // 출발지점 방문 표시
        visited[x][y] = 1;
        
        for(int i=0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if( nx<0 || nx>=N || ny<0 || ny>=M){
            // 지도 범위를 벗어나면 continue;
                continue;
            }
            if(map[nx][ny] != 0 || visited[nx][ny] == 1){
            // 빈칸이 아니거나, 이미 방문한 곳이면 continue;
                continue;
            }

            // 새로 감염
            visited[nx][ny] = 1; // 방문 표시
            q.push({nx,ny}); // q에 넣기 
            cnt++; // 새로 감염된 개수 ++ 
        }
    }
    return cnt;
}

int virusDiffuse(pair<int,int> w1, pair<int,int> w2, pair<int,int> w3){
    // 벽 3개 세우기
    map[w1.first][w1.second] = 1;
    map[w2.first][w2.second] = 1;
    map[w3.first][w3.second] = 1;

    int cnt = BFS();

    // 벽 3개 원상복구
    map[w1.first][w1.second] = 0;
    map[w2.first][w2.second] = 0;
    map[w3.first][w3.second] = 0;

    // 감염된 칸 수 리턴
    return cnt;
}

int main(){
    cin>>N>>M;
    int safety = 0;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin>>map[i][j];
            if(map[i][j]==0){ //빈칸
                safe.push_back(make_pair(i,j));
                safety++;
            }
            else if(map[i][j] == 2){ // 바이러스
                virus.push(make_pair(i,j));
            }
        }
    }
    int minInfection = MAX;
    for(int i=0;i<safe.size()-2;i++){
        for(int j=i+1;j<safe.size()-1;j++){
            for(int k=j+1;k<safe.size();k++){
                int tmp = virusDiffuse(safe[i],safe[j],safe[k]);
                // 더 작은 값이면 업데이트
                if(minInfection>tmp) minInfection = tmp;
            }
        }
    }
    // 안전한 영역 = 빈칸 - 감염칸 - 세운 벽 3개
    int ans = safety - minInfection - 3;
    cout<<ans<<endl;

    return 0;
}