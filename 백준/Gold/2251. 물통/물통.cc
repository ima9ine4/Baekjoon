#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int A,B,C;
    cin>>A>>B>>C;
    queue<pair<pair<int,int>,int>> q;
    vector<int> ans;
    bool visited[201][201][201];
    int a,b,c;
    q.push(make_pair(make_pair(0,0),C));

    while(!q.empty()){
        a = q.front().first.first;
        b = q.front().first.second;
        c = q.front().second;
        q.pop();

        if(visited[a][b][c]){
            continue;
        }

        visited[a][b][c] = true;

        if(a==0){
            ans.push_back(c);
        }
        // A->B
        if(a>B-b){
            q.push(make_pair(make_pair(a-B+b,B),c));
        }else{
            q.push(make_pair(make_pair(0,b+a),c));
        }

        //A->C
        if(a>C-c){
            q.push(make_pair(make_pair(a-C+c,b),c));
        }else{
            q.push(make_pair(make_pair(0,b),c+a));
        }

        // B->A
        if(b>A-a){
            q.push(make_pair(make_pair(A,b-A+a),c));
        }else{
            q.push(make_pair(make_pair(a+b,0),c));
        }

        // B->C
        if(b>C-c){
            q.push(make_pair(make_pair(a,b-C+c),C));
        }else{
            q.push(make_pair(make_pair(a,0),c+b));
        }

        // C->A
        if(c>A-a){
            q.push(make_pair(make_pair(A,b),c-A+a));
        }else{
            q.push(make_pair(make_pair(a+c,b),0));
        }

        // C->B
        if(c>B-b){
            q.push(make_pair(make_pair(a,B),c-B+b));
        }else{
            q.push(make_pair(make_pair(a,b+c),0));
        }

    }

    sort(ans.begin(),ans.end());
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;

}