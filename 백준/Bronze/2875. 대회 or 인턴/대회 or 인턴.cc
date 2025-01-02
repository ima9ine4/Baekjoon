#include <iostream>
using namespace std;

int main(){
    int n,m,k;
    cin>>n>>m>>k;
    int girls = n/2; // 여자로 구성할 수 있는 팀 수 
    int girlsrest = n%2;
    int boys = m; // 남자로 구성할 수 있는 팀 수
    int teams;
    int rest = girlsrest;

    if(girls == boys){
        teams = girls;
        rest = 0;
    }else if(girls < boys){
        teams = girls;
        rest += boys - teams;
    }else{
        teams = boys;
        rest += (girls - teams) * 2;
    }
    while(k>0){
        k -= rest;
        if(k<=0) break;
        teams--;
        rest = 3;
    }
    cout<<teams<<endl;
}