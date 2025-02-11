#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n; cin>>n;
    vector<int> arr(n);
    int arrMax = 0;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        if(arr[i]>arrMax){
            arrMax = arr[i];
        }
    }
    vector<int> dp(10001,0);
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 3;
    dp[4] = 4;
    dp[5] = 5;

    for(int i=6;i<=arrMax;i++){
        dp[i] = dp[i-6] + i;
    }

    for(int i=0;i<n;i++){
        cout<<dp[arr[i]]<<endl;
    }

}