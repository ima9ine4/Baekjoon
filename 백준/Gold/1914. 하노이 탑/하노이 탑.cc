#include <iostream>
#include <cmath>
#include <stdio.h>
using namespace std;

void Hanoi(int n, int a, int b, int c){
    if(n>0){
        Hanoi(n-1, a, c, b);
        cout<<a<<" "<<c<<'\n';
        Hanoi(n-1, b, a, c);
    }
}

int main() {
    int N; cin>>N;
    
    string tmp = to_string(pow(2,N));
    int dot = tmp.find('.');
    tmp = tmp.substr(0,dot);
    tmp[tmp.length() - 1] -= 1;
    cout<<tmp<<'\n';

    if(N<=20){
        Hanoi(N,1,2,3);
    }
    return 0;
}