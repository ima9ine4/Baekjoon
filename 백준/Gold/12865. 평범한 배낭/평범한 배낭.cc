#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n,k; cin>>n>>k;
    vector<int> weights (n+1,0);
    vector<int> values (n+1,0);
    vector<vector<int>> dp(n+1, vector<int>(k+1,0)); // 물건의 수, 최대 무게 
    for(int i=1;i<n+1;i++){
        cin>>weights[i]>>values[i];
    }

    for(int i=1;i<n+1;i++){
        for(int j=1;j<k+1;j++){
            // i번째 물품의 무게가 배낭보다 크면
            if(weights[i]>j){
                dp[i][j] = dp[i-1][j];
            }else{ //넣을 수 있으면
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-weights[i]] + values[i]);
            }
        }
    }
    cout<<dp[n][k]<<endl;
}