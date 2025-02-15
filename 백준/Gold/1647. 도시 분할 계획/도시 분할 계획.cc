#include <iostream>
#include <vector>
#include <climits>
#include <queue>
using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n,m; cin>>n>>m;
    vector<int> distance(n+1,INT_MAX); // 집 번호 1부터 
    vector<vector<pair<int,int>>> adjList(n+1); // 집 번호 1부터 

    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        adjList[a].push_back({b,c});
        adjList[b].push_back({a,c});
    }

    int mstNode = 1;
    int mstCost = 0;
    int now = 1; // 1번 노드부터 시작
    int maxCost = 0;
    distance[now] = -1;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;

    while(mstNode != n){ // 모든 원소를 선택할 때까지

        // 1. 인접한 노드의 거리 업데이트
        for(int i=0;i<adjList[now].size();i++){ // 인접한 노드 수만큼
            int adjNode = adjList[now][i].first;
            int adjCost = adjList[now][i].second;
            
            if(distance[adjNode]!=-1 && distance[adjNode]>adjCost){ // 현재 노드에서부터 더 적은 비용으로 도달가능하면 업데이트
                distance[adjNode] = adjCost;
                q.push({adjCost,adjNode});
            }
        }
        
        int tmpCost = 0;
        int tmpNode = 0;
        // 2. distance 벡터에서 가장 짧은 비용으로 도달가능한 노드 찾기 
        while(!q.empty() && mstNode < n){
            tmpNode = q.top().second;
            tmpCost = q.top().first;
            q.pop();

            if(distance[tmpNode]==-1) continue;

            now = tmpNode;
            mstCost += tmpCost;
            if(tmpCost>maxCost) maxCost = tmpCost;
            mstNode++;
            distance[now] = -1; // 방문 처리
            break;
        }

    }
    int answer = mstCost - maxCost;
    cout<<answer<<endl;
}