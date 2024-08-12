#include <iostream>
using namespace std;

int main() {
    int n; cin>>n;
    long long dp[91];
    dp[0] = 0;
    dp[1] = 1;
    if(n==0||n==1){
        cout<<n<<endl;
    }else{
        for(int i=2;i<n+1;i++) {
            dp[i] = dp[i-1]+dp[i-2];
        }
    cout<<dp[n]<<endl;
    }
    return 0;
}