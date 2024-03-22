#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
    int max = -1; int now = 0;
    int maxN = 0; int maxM = 0;
    for(int i=1;i<=9;i++) {
        for(int j=1;j<=9;j++){
            cin>>now;
            if(now>max){
                max = now;
                maxN = i; maxM = j;
            }
        }
    }
    cout<<max<<endl;
    cout<<maxN<<" "<<maxM<<endl;
    return 0;
}