#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    int n; cin>>n;
    vector<int>arr(n,0);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr.begin(),arr.end());
    int cnt=0;
    for(int k=0;k<n;k++){
        long find = arr[k];
        int i=0; int j=n-1;

        while(i<j){
            if(arr[i]+arr[j]==find){
                if((i!=k)&&(j!=k)){
                    cnt++; break;
                }
                else if(i==k){
                    i++;
                }else if(j==k){
                    j--;
                }
            }else if(arr[i]+arr[j]<find){
                i++;
            }else j--;
        }
    }
    cout<<cnt<<endl;
}