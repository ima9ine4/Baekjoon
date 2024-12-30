#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main(){
    int n; cin>>n;
    vector<string> strs(n);
    vector<int> alpha(26,0);

    for(int i=0;i<n;i++){
        cin>>strs[i];
    }
    
    for(int i=0;i<n;i++){//n개의 단어 순회
        int pow = 1;
        for(int j=strs[i].size()-1;j>=0;j--){//한 단어에서의 알파벳 순회
               alpha[strs[i][j]-'A'] += pow;
               pow *= 10;
        }
    }
    sort(alpha.begin(),alpha.end());
    
    int num = 9;
    int ans = 0;
    for(int i=25;i>=0;i--){
        if(alpha[i]==0) break;
        ans += alpha[i] * num;
        num--;
    }

    cout<<ans<<endl;

    return 0;
}