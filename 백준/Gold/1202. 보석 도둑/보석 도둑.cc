#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main(){
    int n,k;
    cin>>n>>k;
    vector<pair<int,int>> jewels(n);
    vector<int> bags(k);
    for(int i=0;i<n;i++){
        cin>>jewels[i].first>>jewels[i].second;
    }
    for(int i=0;i<k;i++){
        cin>>bags[i];
    }

    sort(bags.begin(), bags.end());
    sort(jewels.begin(), jewels.end());

    long long ans = 0;
    int jewelIndex = 0;

    priority_queue<int> pq;

    for(int i=0;i<k;i++){
        for(int j=jewelIndex;j<n;j++){
            if(bags[i]>=jewels[j].first){
                pq.push(jewels[j].second);
                jewelIndex++;
            }else{
                break;
            }
        }
        if(!pq.empty()){
            ans += pq.top();
            pq.pop();
        }
    }

    cout<<ans<<endl;
}