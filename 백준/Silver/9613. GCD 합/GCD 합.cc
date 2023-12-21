#include <iostream>
#include <vector>
using namespace std;

int gcd(int a, int b){
    if(a < b){ //swap
        int tmp = a;
        a = b; b = tmp;
    }
    int r = a % b;
    if (r==0) {
        return b;
    }else{
        return gcd(b,r);
    } 
}
int main() {
    int result = gcd(30,20);
    int t; cin>>t;
    long long ans;
    while(t--){
        ans = 0;
        int n; cin >> n;
        vector<int>arr(n);
        for(int i=0;i<n;i++){
            cin >> arr[i];
        }
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int result = gcd(arr[i],arr[j]);
                ans += result;
            }
        }
    cout << ans << endl;
    }
    return 0;
}