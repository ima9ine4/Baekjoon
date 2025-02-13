#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n,m; cin>>n>>m;
    vector<vector<int>> adjMatrix(n+1, vector<int>(n+1,0));
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        adjMatrix[a][b] = 1;
        adjMatrix[b][a] = 1;
    }
    int ret = 4001;
    for(int a=1;a<=n;a++){
        for(int b = a+1;b<=n;b++){
            if(adjMatrix[a][b]==1){
                for(int c=b+1;c<=n;c++){
                    if(adjMatrix[a][c]==1 && adjMatrix[b][c]==1){
                        // a,b,c 선택
                        int cnt = 0;
                        for(int i=1;i<=n;i++){
                            if(adjMatrix[a][i]==1){
                                cnt++;
                            }
                            if(adjMatrix[b][i]==1){
                                cnt++;
                            }
                            if(adjMatrix[c][i]==1){
                                cnt++;
                            }
                        }
                        cnt-=6; // a,b,c 간의 친구 count 빼기
                        if(cnt<ret) ret = cnt;
                    }
                }
            }
        }
    }
    if(ret==4001) ret = -1;
    cout<<ret<<endl;
}