#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n; cin>>n;
    vector<int> arr(n);
    vector<vector<int>> dp(2,vector<int>(n,0));
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int ans = arr[0];
    dp[0][0] = arr[0];
    dp[1][0] = arr[0];
    for(int i=1;i<n;i++){
        dp[0][i] = max(dp[0][i-1]+arr[i], arr[i]);
        dp[1][i] = max(dp[1][i-1]+arr[i], dp[0][i-1]);
        ans = max(ans, max(dp[0][i],dp[1][i]));
    }
    cout<<ans<<'\n';
    return 0;
}