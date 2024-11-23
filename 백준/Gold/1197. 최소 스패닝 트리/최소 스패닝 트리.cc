#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<pair<int, pair<int,int>>> V;
vector<int> parent;

int Find(int a){
    if(parent[a]!=a){
        parent[a] = Find(parent[a]);
    }
    return parent[a];
}

bool Union(int a, int b){
    int a_root = Find(a);
    int b_root = Find(b);
    if(a_root != b_root){
        parent[b_root] = a_root;
        return true;
    }else{
        return false;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int v,e; cin>>v>>e;
    int a,b,c;
    for(int i=0;i<e;i++){
        cin>>a>>b>>c;
        V.push_back(make_pair(c,make_pair(a,b)));
    }
    sort(V.begin(),V.end()); // 정렬
    parent.resize(v+1);
    
    for(int i=1;i<v+1;i++){
        parent[i] = i; // singleton set 초기화
    }
    int edgeNum = 0; // 선택된 간선의 개수
    int weightSum = 0; // MST 가중치 합
    for(int i=0;i<e;i++){
        if(edgeNum==v-1) break;
        int cost = V[i].first;         // 간선의 가중치
        int from = V[i].second.first; // 간선의 시작 정점
        int to = V[i].second.second;  // 간선의 끝 정점
        if(Union(from,to)){
            edgeNum++;
            weightSum += cost;
        }
    }
    cout<<weightSum<<"\n";
}