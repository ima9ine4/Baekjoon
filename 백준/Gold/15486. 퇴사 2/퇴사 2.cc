#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
struct Meeting{
    int time;
    int price;
};

int main(){
    int n; cin>>n;
    vector<Meeting> arr(n+1);
    vector<int> dp(n+2,0);
    for(int i=1;i<n+1;i++){
        cin>>arr[i].time>>arr[i].price;
    }
    for(int i=0;i<n+1;i++){
        dp[i+1] = max(dp[i+1],dp[i]);

        if(i+arr[i].time<=n+1){
            dp[i+arr[i].time] = max(dp[i+arr[i].time], dp[i]+arr[i].price);
        }
        
    }
    cout<<dp[n+1]<<endl;
}