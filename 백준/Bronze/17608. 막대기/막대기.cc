#include <iostream>
using namespace std;

int main() {
    int N; cin>>N;
    int cnt = 1; //가장 오른쪽 막대기는 항상 보임
    int arr[N];
    for(int i=1;i<N+1;i++) {
        cin>>arr[i];
    }
    int max = arr[N];
    for(int i=N;i>0;i--){
        if(arr[i]>max){
            cnt++;
            max = arr[i];
        }
    }
    cout<<cnt<<endl;
    return 0;
}