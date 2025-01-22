#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(){
    ios::sync_with_stdio(false);      
    cin.tie(NULL);      
    cout.tie(NULL);

    int n,k; cin>>n;
    priority_queue<int,vector<int>> maxheap;
    priority_queue<int, vector<int>, greater<int>> minheap;
    for(int i=0;i<n;i++){
        cin>>k;

        if(maxheap.empty() || k <= maxheap.top()){
            //0번째 원소이거나 최댓값보다 작으면
            maxheap.push(k);
        }else{
            minheap.push(k);
        }

        if(maxheap.size() > minheap.size() + 1){
            //maxheap에서 minheap으로 옮기기
            minheap.push(maxheap.top());
            maxheap.pop();
        }else if(minheap.size()>maxheap.size()){
            maxheap.push(minheap.top());
            minheap.pop();
        }
        
        cout<<maxheap.top()<<'\n';
    }
   
    return 0;
}