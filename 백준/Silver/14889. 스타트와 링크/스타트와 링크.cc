#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int main(){
    int n; cin>>n;
    vector<vector<int>> s(n,vector<int>(n,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>s[i][j];
        }
    }
    vector<int> num(n);
    for(int i=0;i<n;i++){
        num[i] = i+1;
    }
    vector<bool> mask(n);
    fill(mask.end()-n/2, mask.end(), true);

    int ans = INT_MAX;

    do{
        vector<int> start, link;
        for(int i=0;i<n;i++){
            if(mask[i]){
                start.push_back(num[i]);
            }else{
                link.push_back(num[i]);
            }
        }

        int startS = 0;
        int linkS = 0;
        for(int i=0;i<n/2;i++){
            for(int j=i+1;j<n/2;j++){
                startS += s[start[i]-1][start[j]-1] + s[start[j]-1][start[i]-1];
                linkS += s[link[i]-1][link[j]-1] + s[link[j]-1][link[i]-1];
            }
        }
        int diff = (startS>linkS) ? startS-linkS : linkS-startS;
        if(ans > diff) ans = diff;
    }while(next_permutation(mask.begin(),mask.end()));
    
    cout<<ans<<endl;
}