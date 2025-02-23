#include <iostream>
#include <vector>
using namespace std;
vector<int> plan;
vector<int> cities;
int n,m;

int Find(int a){
    if(a == cities[a]){
        return a;
    }else{
        return cities[a] = Find(cities[a]);
    }
}

void Union(int a, int b){
    int rootA = Find(a);
    int rootB = Find(b);
    if(rootA != rootB){
        
        if(rootA < rootB){
            cities[b] = rootA;
        }else{
            cities[a] = rootB;
        }
        Union(rootA,rootB);
    }
}

int main(){
    cin>>n; cin>>m;
    plan = vector<int>(m,0);
    cities = vector<int>(n+1,0);
    for(int i=1;i<=n;i++){
        cities[i] = i;
    }

    int tmp;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>tmp;
            if(i<=j && tmp){
                Union(i,j);
            }
        }
    }

    for(int i=0;i<m;i++){
        cin>>plan[i];  
    }
    int root = Find(plan[0]);

    int NotConntected = 0;
    for(int i=1;i<m;i++){
        if(root != Find(plan[i])){
            NotConntected = 1;
            break;
        }
    }

    if(NotConntected) cout<<"NO"<<endl;
    else cout<<"YES"<<endl;
}