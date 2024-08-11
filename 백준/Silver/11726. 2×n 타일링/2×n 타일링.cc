#include <iostream>
using namespace std;

int main(){
    int n; cin>>n;
    int dp[n+1];
    if(n==1||n==2){
        cout<<n<<endl;
    }else{
        dp[1] = 1;
        dp[2] = 2;
        for(int i=3;i<n+1;i++){
            dp[i] = (dp[i-2] + dp[i-1])%10007;
        }
        cout<<dp[n]<<endl;
    }
    return 0;
}