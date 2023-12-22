#include <iostream>
using namespace std;
int gcd(int x, int y){
    if(x<y){
        int tmp = x;
        x = y; y = tmp;
    }
    int r = x%y;
    if(r==0){
        return y;
    }else{
        return gcd(y,r);
    }
}
int main() {
    int a,b,c,d,mom,son; cin>>a>>b>>c>>d;
    son = a*d + b*c; mom = b*d;
    int res = gcd(son,mom);
    son /= res; mom /= res;
    cout << son << " " << mom <<endl;
    return 0;
}