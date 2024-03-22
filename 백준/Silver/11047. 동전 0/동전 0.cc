#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int n,k; cin>>n>>k;
    vector<int> arr;
    for(int i=0;i<n;i++) {
        int tmp;
        cin>>tmp;
        arr.push_back(tmp);
    }
    sort(arr.begin(),arr.end(), greater<int>());
    // for(int i=0;i<arr.size();i++){
    //     cout<<arr.at(i)<<endl;
    // }
    int sum = 0;
    int cnt = 0;
    for(int i=0;i<n;i++){
        if(arr[i]<=k){
            int tmpcnt = 0;
            tmpcnt += (k / arr[i]); // 몫을 cnt에 저장
            k -= (arr[i]*tmpcnt);
            cnt += tmpcnt;
        }
    }
    cout<<cnt<<endl;
    return 0;
}