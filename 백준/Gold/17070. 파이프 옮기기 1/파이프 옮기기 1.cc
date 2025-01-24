#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(){
    int n; cin>>n;
    vector<vector<int>> map(n+1,vector<int> (n+1));
    queue<pair<pair<int,int>,int>> q;
    // 입력
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>map[i][j];
        }
    }

    int cnt = 0;

    q.push(make_pair(make_pair(1,1),0));
    while(!q.empty()){
        int a = q.front().first.first;
        int b = q.front().first.second;
        int c = q.front().second;
        q.pop();

        if((a==n&&b==n-1&&c==0)||(a==n-1&&b==n&&c==1)||(a==n-1&&b==n-1&&c==2)){
            cnt++;
            continue;
        }

        if(c==0){
            if(b + 2 <= n && map[a][b+2]==0){
                q.push(make_pair(make_pair(a,b+1),0));
            }
            if(a + 1 <= n && b + 2 <= n &&map[a][b+2]==0&&map[a+1][b+1]==0&&map[a+1][b+2]==0){
                q.push(make_pair(make_pair(a,b+1),2));
            }
        }

        if(c==1){
            if(a + 2 <= n && map[a+2][b]==0){
                q.push(make_pair(make_pair(a+1,b),1));
            }
            if(a + 2 <= n && b + 1 <= n && map[a+1][b+1]==0&&map[a+2][b]==0&&map[a+2][b+1]==0){
                q.push(make_pair(make_pair(a+1,b),2));
            }

        }

        if(c==2){
            if(b + 2 <= n && map[a+1][b+2]==0){
                q.push(make_pair(make_pair(a+1,b+1),0));
            }
            if(a + 2 <= n && map[a+2][b+1]==0){
                q.push(make_pair(make_pair(a+1,b+1),1));
            }
            if(a + 2 <= n && b + 2 <= n && map[a+1][b+2]==0&&map[a+2][b+1]==0&&map[a+2][b+2]==0){
                q.push(make_pair(make_pair(a+1,b+1),2));
            }
        }
        
    }
        cout<<cnt<<endl;
}