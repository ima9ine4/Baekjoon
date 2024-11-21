#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n; cin>>n;
    vector<pair<int,int>> list(n);
    int s,f;
    for(int i=0;i<n;i++){
        cin>>s>>f;
        list[i]=make_pair(f,s);
    }
    sort(list.begin(),list.end());
    int time = list[0].first; // 회의 끝 시간
    int ans = 1; // 회의 개수
    for(int i=1;i<n;i++){
        if(list[i].second >= time){ //어떤 회의의 시작시간이 time 이후라면
            ans++;
            time = list[i].first; //해당 회의 끝나는 시간으로 time 업데이트
        }
    }
    cout<<ans<<endl;
}