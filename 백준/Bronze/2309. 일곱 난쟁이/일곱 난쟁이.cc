#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int dwarf[9];
    int sum = 0;
    for(int i=0;i<9;i++) {
        cin >> dwarf[i];
        sum += dwarf[i];
    }
    sort(dwarf,dwarf+9);
    for(int i=0;i<9;i++){
        for(int j=i+1;j<9;j++){
            if(sum-dwarf[i]-dwarf[j]==100){
                for(int k=0;k<9;k++){
                    if (k==i || k==j) continue;
                    cout<<dwarf[k]<<endl;
                }
                return 0;
            }
        }
    }
    return 0;
}