#include <iostream>
using namespace std;

int gcd(int a, int b){
    if(a<b){
        int tmp = a;
        a = b; b = tmp;
    }
    int r = a % b;
    if(r==0){
        return b;
    }else{
        return gcd(b,r);
    }
}
int main() {
    int n; cin>>n;
    int mom, son, gcdResult;
    int first; cin>>first;
    for(int i=1;i<n;i++){
        int tmp; cin>>tmp;
        gcdResult = gcd(first, tmp);
        mom = first / gcdResult;
        son = tmp / gcdResult;
        cout << mom << "/" << son << endl;
    }
    return 0;
}