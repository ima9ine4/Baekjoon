#include <iostream>
#include <vector>
using namespace std;

int main(){
    int N,S,M; cin>>N>>S>>M;
    vector<int> volumes(N+1);
    for(int i=1;i<=N;i++){
        cin>>volumes[i];
    }
    vector<vector<int>> dp(N+1,vector<int>(M+1,0));
    dp[0][S] = 1;
    for(int i=0;i<N;i++){
        for(int j=0;j<=M;j++){
            if(dp[i][j]){
                if(j+volumes[i+1]<=M){
                    dp[i+1][j+volumes[i+1]] = 1;
                }
                if(j-volumes[i+1]>=0){
                    dp[i+1][j-volumes[i+1]] = 1;
                }
            }
        }
    }
    int ans = -1;
    for(int i=0;i<=M;i++){
        if(dp[N][i]){
            ans = i;
        }
    }
    cout<<ans<<endl;
}