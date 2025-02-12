#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main(){
    int n, m; cin>>n>>m;
    vector<vector<pair<int,int>>> adjList(n+1);
    int a,b,c;
    for(int i=0;i<m;i++){
        cin>>a>>b>>c;
        adjList[a].push_back({b,c});
        adjList[b].push_back({a,c});
    }
    
    vector<int> distance(n+1, INT_MAX);
    int visitCnt = 1;
    int ans = 0;
    int nowNode = 1;

    while(visitCnt<n){
        distance[nowNode] = -1; // 방문 처리

        // 선택 노드와 인접한 노드의 distance vector 업데이트
        for(int i=0;i<adjList[nowNode].size();i++){
            int a = adjList[nowNode][i].first;
            int b = adjList[nowNode][i].second;
            if(distance[a]>b) distance[a] = b; // 더 짧은 경로이면 업데이트
        }

        // 도달 가능한 노드 중 가장 가까운 노드 찾기
        int nextNode; //node 번호
        int tmp = INT_MAX;
        for(int i=1;i<=n;i++){
            if(distance[i]!=-1 && distance[i]<tmp){
                //방문하지 않았고, 거리가 더 작으면 업데이트
                nextNode = i;
                tmp = distance[i];
            }
        }

        ans+= distance[nextNode]; // 다음 노드 가중치 합산
        nowNode = nextNode;
        visitCnt++;
    }
    cout<<ans<<endl;
}