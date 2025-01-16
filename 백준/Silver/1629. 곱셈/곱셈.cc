#include <iostream>
using namespace std;

long long fast_pow(long a, long b, long c){
    if(b==1) return a%c;
    long long tmp = fast_pow(a,b/2,c);
    tmp = (tmp*tmp)%c;
    if(b%2==0) return tmp;
    else return (tmp*a)%c;
}

int main(){
    long long a,b,c;
    cin>>a>>b>>c;
    long long ans = fast_pow(a,b,c);
    cout<<ans<<endl;
}