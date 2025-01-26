#include <iostream>
#include <vector>
using namespace std;
int n, ans;
vector<pair<int,int>> eggs;

void DFS(int idx){
    if(idx==n){
        // 모든 계란을 다 손에 들었음
        int cnt = 0;
        for(int i=0;i<n;i++){
            if(eggs[i].first<=0){
                // 깨진 계란 세기
                cnt++;
            }
        }
        ans = max(ans,cnt);
        return;
    }

    if(eggs[idx].first <= 0){ // 이미 깨진 계란이면 다음으로
        DFS(idx+1);
    }else{
        bool isHit = false;
        for(int i=0;i<n;i++){
            if(i==idx || eggs[i].first <= 0){
                // 현재 손에 든 계란이거나 이미 깨진 계란인 경우
                continue;
            }

            isHit = true;
            // 상대 계란의 무게만큼 내구도 깎임
            eggs[i].first -= eggs[idx].second;
            eggs[idx].first -= eggs[i].second;

            DFS(idx+1);

            // 복구
            eggs[i].first += eggs[idx].second;
            eggs[idx].first += eggs[i].second;
        }
        if(!isHit){
            DFS(n);
        }
    }
}

int main(){
    cin>>n;
    int s,w;
    for(int i =0;i<n;i++){
        cin>>s>>w; // 내구도, 무게
        eggs.push_back({s,w});
    }
    ans = 0;
    DFS(0);
    cout<<ans<<endl;

}