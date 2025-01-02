#include<iostream>
#include<algorithm>
#include<queue>
#include<set>

using namespace std;

int main(){
    int a,b,c;
    cin>>a>>b>>c;
    queue<pair<pair<int,int>,int>> q;
    set <pair<pair<int,int>,int>> check;

    q.push(make_pair(make_pair(a,b),c));
    
    if((a+b+c)%3 != 0){
        cout<<0<<endl;
        return 0;
    }

    bool ans = 0;
    while(!q.empty()){
        int a = q.front().first.first;
        int b = q.front().first.second;
        int c = q.front().second;

        q.pop();

        if(a==b && b==c){
            ans = 1;
            break;
        }
        int aa, bb, cc;

        if(a>b){
            aa = a-b;
            bb = b+b;
            cc = c;
            if(check.find(make_pair(make_pair(aa,bb),cc)) == check.end()){
                check.insert(make_pair(make_pair(aa,bb),cc));
                q.push(make_pair(make_pair(aa,bb),cc));
            }
        }else if(a<b){
            bb = b-a;
            aa = a+a;
            cc = c;
            if(check.find(make_pair(make_pair(aa,bb),cc)) == check.end()){
                check.insert(make_pair(make_pair(aa,bb),cc));
                q.push(make_pair(make_pair(aa,bb),cc));
            }
        }

        if(a>c){
            aa = a-c;
            cc = c+c;
            bb = b;
            if(check.find(make_pair(make_pair(aa,bb),cc)) == check.end()){
                check.insert(make_pair(make_pair(aa,bb),cc));
                q.push(make_pair(make_pair(aa,bb),cc));
            }
        }else if(c>a){
            cc = c-a;
            aa = a+a;
            bb = b;
            if(check.find(make_pair(make_pair(aa,bb),cc)) == check.end()){
                check.insert(make_pair(make_pair(aa,bb),cc));
                q.push(make_pair(make_pair(aa,bb),cc));
            }
        }

        if(b>c){
            bb = b-c;
            cc = c+c;
            aa = a;
            if(check.find(make_pair(make_pair(aa,bb),cc)) == check.end()){
                check.insert(make_pair(make_pair(aa,bb),cc));
                q.push(make_pair(make_pair(aa,bb),cc));
            }
        }else if(c>b){
            cc = c-b;
            bb = b+b;
            aa = a;
            if(check.find(make_pair(make_pair(aa,bb),cc)) == check.end()){
                check.insert(make_pair(make_pair(aa,bb),cc));
                q.push(make_pair(make_pair(aa,bb),cc));
            }
        }        
    }
    cout<<ans<<endl;
}