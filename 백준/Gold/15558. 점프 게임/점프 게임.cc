#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
using namespace std;
int n, k;

int bfs(vector<int>& arrL, vector<int>& arrR) {
    int isclear = 0;
    // 큐: { {칸 번호, 줄 (0:왼쪽, 1:오른쪽)}, 시간 }
    queue<pair<pair<int,int>,int>> q;
    q.push({{1, 0}, 0});  // 처음 상태: 왼쪽 줄 1번 칸, 시간 0
    
    // 방문 배열: 칸 번호의 최대 범위는 n+k까지 사용합니다.
    bool visited[2][n+k+1];
    memset(visited, false, sizeof(visited)); 

    while(!q.empty()){
        int index = q.front().first.first;
        int lane  = q.front().first.second;
        int time  = q.front().second;
        q.pop();
        
        // 이동 후 시간이 time+1가 되므로, 
        // 현재 칸 번호가 time 이하이면 이미 사라진 칸입니다.
        if(index <= time) continue;
        
        if(visited[lane][index]) continue;
        visited[lane][index] = true;
        
        // 게임 클리어 조건: (문제에서는 "N번 칸보다 더 큰 칸"으로 이동 시 클리어)
        if(index > n){
            isclear = 1;
            break;
        }
        
        // 3가지 이동 – 단, 이동 후 시간은 time+1이고, 
        // 이동한 칸 번호가 time+1보다 커야 안전합니다.
        
        // 1. 반대편 줄로 점프 : 현재 줄이 0이면 오른쪽, 1이면 왼쪽으로 이동 (칸 번호는 index+k)
        if(index + k > time + 1 && index + k <= n+k) {
            if(lane == 0 && arrR[index+k] == 1)
                q.push({{index+k, 1}, time+1});
            if(lane == 1 && arrL[index+k] == 1)
                q.push({{index+k, 0}, time+1});
        }
        
        // 2. 한 칸 앞으로 이동 : 같은 줄, 칸 번호 index+1
        if(index + 1 > time + 1 && index + 1 <= n+k) {
            if(lane == 0 && arrL[index+1] == 1)
                q.push({{index+1, 0}, time+1});
            if(lane == 1 && arrR[index+1] == 1)
                q.push({{index+1, 1}, time+1});
        }
        
        // 3. 한 칸 뒤로 이동 : 같은 줄, 칸 번호 index-1  
        // (이동 후 칸 번호가 time+1보다 커야 하므로 index-1 > time+1 이어야 함)
        if(index - 1 > time + 1 && index - 1 > 0) {
            if(lane == 0 && arrL[index-1] == 1)
                q.push({{index-1, 0}, time+1});
            if(lane == 1 && arrR[index-1] == 1)
                q.push({{index-1, 1}, time+1});
        }
    }
    
    return isclear;
}

int main(){
    cin >> n >> k;
    string strL, strR;
    cin >> strL >> strR;
    
    // 인덱스 1부터 사용하며, n+k까지 안전한 칸(1)으로 초기화합니다.
    vector<int> arrL(n+k+1, 1);
    vector<int> arrR(n+k+1, 1);
    
    for(int i = 1; i <= n; i++){
        arrL[i] = strL[i-1] - '0';
    }
    for(int i = 1; i <= n; i++){
        arrR[i] = strR[i-1] - '0';
    }
    
    int ans = bfs(arrL, arrR);
    cout << ans << endl;
}
