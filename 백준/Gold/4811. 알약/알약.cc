#include <iostream>
using namespace std;

int main(){
    long long int dp[31][31];
    for(int i=0;i<=30;i++){
        dp[0][i] = 1;
    }
    for(int i=1;i<=30;i++){
        for(int j=0;j<=30;j++){
            if(j==0) dp[i][j] = dp[i-1][1];
            else dp[i][j] = dp[i-1][j+1]+dp[i][j-1];
        }
    }
    while(true){
        int ipt; cin>>ipt;
        if(ipt==0) break;
        cout<<dp[ipt][0]<<endl;
    }
}