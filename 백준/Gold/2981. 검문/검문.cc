#include <iostream>
#include <algorithm>
using namespace std;

int gcd(int a, int b){
    if(a<b){
        int tmp = a;
        a = b; b = tmp;
    }
    int r = a % b;
    if(r != 0){
        return gcd(b,r);
    }else{
        return b;
    }
}
void factor(int a) {
	if (a <= 0) {
		return;
	}

	for (int i = 1; i <= a / 2; i++) {
		if (a % i == 0) {
			if(i!=1) cout << i << " ";
		}
	}
    cout << a << endl;
}
int main(){
    int N; cin>>N;
    int arr[N];
    for(int i=0;i<N;i++){
        int tmp; cin>>tmp;
        arr[i]=tmp;
    }
    sort(arr,arr+N);
    int diff[N-1];
    for(int i=0;i<N;i++){
        diff[i] = arr[i+1]-arr[i];
    }
    int ans = diff[0];
    for(int i=0;i<N-2;i++){
        ans = gcd(ans,diff[i+1]);
    }
    factor(ans);
    cout<<endl;
}