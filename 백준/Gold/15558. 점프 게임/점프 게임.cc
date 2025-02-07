#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
using namespace std;
int n,k;

int bfs(vector<int>& arrL, vector<int>& arrR){
    int isclear = 0;
    queue<pair<pair<int,int>,int>> q; //칸, 줄, 시간
    q.push({{1,0},0}); // 처음 상태, 1번칸 왼쪽 줄, 시간 0
    bool visited[2][n+k+1];
    memset(visited, false, sizeof(visited)); 

    while(!q.empty()){
        int index = q.front().first.first;
        int arr = q.front().first.second;
        int time = q.front().second;
        q.pop();
        if(index <= time) continue;

        if(visited[arr][index]){
            continue;
        }
        visited[arr][index] = true;

        if(index>=n){
            isclear = 1;
            break;
        }

        if(arr==0){// 왼쪽 줄 위치
            if(arrR[index+k] == 1){
                //반대편 줄로 점프 가능하면
                q.push({{index+k,1},time+1});
            }
            if(arrL[index+1] == 1){
                //한 칸 앞으로 이동 가능하면
                q.push({{index+1,0},time+1});
            }
            if((index != 1) && (index-2 > time) &&(arrL[index-1]==1)){
                //한 칸 뒤로 이동 가능하면
                q.push({{index-1,0},time+1});
            }
        }else{ // 오른쪽 줄 위치
            if(arrL[index+k] == 1){
                //반대편 줄로 점프 가능하면
                q.push({{index+k,0},time+1});
            }
            if(arrR[index+1] == 1){
                //한 칸 앞으로 이동 가능하면
                q.push({{index+1,1},time+1});
            }
            if((index != 1) && (index-2 > time) &&(arrR[index-1]==1)){
                //한 칸 뒤로 이동 가능하면
                q.push({{index-1,1},time+1});
            }
        }
    }

    if(isclear){
        return 1;
    }else{
        return 0;
    }
}

int main(){
    cin>>n>>k;
    string strL, strR;
    cin>>strL>>strR;

    vector<int> arrL(n+k+1,1);
    vector<int> arrR(n+k+1,1);

    for(int i=1;i<=n;i++){
        arrL[i] = strL[i-1]-48;
        // 문자 -> 숫자 변환 아스키코드 빼주기
        // 0의 아스키코드 값은 48
    }
    for(int i=1;i<=n;i++){
        arrR[i] = strR[i-1]-48;
    }
    
    int ans = bfs(arrL, arrR);
    cout<<ans<<endl;
}