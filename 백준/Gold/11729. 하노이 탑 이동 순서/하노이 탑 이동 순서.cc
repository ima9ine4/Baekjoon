#include <iostream>
using namespace std;

void hanoi(int n, int a, int b, int c){
    if(n==1){
        cout<<a<<" "<<c<<'\n';
        return;
    }
    
    hanoi(n-1, a, c, b);
    cout<<a<<" "<<c<<'\n'; // 가장 큰 1개를 1에서 3으로 옮기기
    hanoi(n-1, b, a, c);
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n; cin>>n;
    int k = 0;
    for(int i=1;i<=n;i++){
        k = 2*k + 1;
    }
    cout<<k<<'\n';
    hanoi(n,1,2,3);

}