#include <iostream>
#include <cstring>
using namespace std;

int main() {
    int n; cin>>n;
    int arr[n][2];
    int t,p;
    int dp[n+5];
    memset(dp, 0, sizeof(int)*(n+5));
    for(int i=1;i<=n;i++) {
        cin>>t>>p;
        if(i+t<=n+1){
            arr[i][0] = t;
            arr[i][1] = p;
        }else{
            arr[i][0] = 0;
            arr[i][1] = 0;
        }
    }
    for(int i=n;i>0;i--){
        t = arr[i][0];
        p = arr[i][1];
        if(t==0){
            dp[i] = dp[i+1];
        }else{
            dp[i] = max(dp[i+1],p+dp[i+t]);
        }
    }
    cout<<dp[1]<<endl;
    return 0;
}