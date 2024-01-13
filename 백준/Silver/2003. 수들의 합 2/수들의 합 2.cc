#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N,M; cin>>N>>M;
    vector<int> arr(N);
    for(int i=0;i<N;i++) {
        cin>>arr[i];
    }
    int left = 0; int right = 0;
    int sum = arr[0]; int cnt = 0;
    while(left<=right&&right<N){
        if(sum<M){
            sum += arr[++right];
        }else if(sum>M){
            if(left==right){
                sum += arr[++right];
            }else{
                sum -= arr[left++];
            }
        }else{
            cnt++;
            if(left==right){
                sum += arr[++right];
            }else{
                sum -= arr[left++];
            }
        }
    }
    cout<<cnt<<endl;
    return 0;
}