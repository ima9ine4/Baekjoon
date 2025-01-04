#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n; cin>>n;
    vector<int> alpha(26,0);
    string tmp;
    for(int i=0;i<n;i++){
        cin>>tmp;
        int pow = 1;
        for(int j=tmp.size()-1;j>=0;j--){
            alpha[tmp[j]-'A'] += pow;
            pow *= 10;
        }
    }
    sort(alpha.begin(),alpha.end());
    int num = 9;
    int ans = 0;
    for(int i=alpha.size()-1;i>=0;i--){
        if(alpha[i]==0) break;
        ans += (alpha[i]*num);
        num--;
    }
    cout<<ans<<endl;
}