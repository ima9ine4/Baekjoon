#include <iostream>
#include <vector>
using namespace std;
vector<int> parent;
vector<int> sz;

int Find(int node) {
    if (parent[node] != node) {
        parent[node] = Find(parent[node]); // 경로 압축
    }
    return parent[node];
}

void Union(int a, int b){
    int a_root = Find(a);
    int b_root = Find(b);

    if(a_root != b_root){
        if(sz[a_root] < sz[b_root]){
            parent[a_root] = b_root;
            sz[b_root] += sz[a_root];
        }else{
            parent[b_root] = a_root;
            sz[a_root] += sz[b_root];
        }
    }
}

void is_same_set(int a, int b){
    cout << (Find(a) == Find(b) ? "YES\n" : "NO\n");
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,m; cin>>n>>m;
    int k,a,b;
    parent.resize(n + 1);
    sz.assign(n + 1, 1);
    for(int i=0;i<=n;i++){
        parent[i] = i;
    }
    while(m--){
        cin>>k>>a>>b;
        if(k==0){
            Union(a,b);
        }else{ //k==1
            is_same_set(a,b);
        }
    }
}