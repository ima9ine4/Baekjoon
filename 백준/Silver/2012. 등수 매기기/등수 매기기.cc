#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    int n; cin>>n;
    vector<int> predicted(n+1,0);
    for(int i=1;i<=n;i++){
        cin>>predicted[i];
    }
    long long ans = 0;
    sort(predicted.begin(), predicted.end());
    for(int i=1;i<=n;i++){
        if(predicted[i]>i){
            ans += predicted[i] - i;
        }else{
            ans += i - predicted[i];
        }
    }
    cout<<ans<<endl;
}