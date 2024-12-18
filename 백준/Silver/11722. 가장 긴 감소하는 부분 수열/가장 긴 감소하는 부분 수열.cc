#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n; cin>>n;
    vector<int> arr(n,0);
    vector<int> dp(n,1);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    for(int i=1; i<n; i++){
        for(int j=0;j<i;j++){
            if(arr[j]>arr[i]){
                dp[i] = max(dp[i],dp[j]+1);
            }
        }
    }
    int ans = 0;
    for(int i=0;i<n;i++){
        if (dp[i]>ans){
            ans = dp[i];
        }
    }
    cout<<ans<<endl;
}