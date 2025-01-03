#include <iostream>
#include <vector>
using namespace std;

void cal(vector<vector<int>>& inputArr, int n, int m){
    for(int i=n; i<n+3; i++){
        for(int j=m; j<m+3; j++){
            inputArr[i][j] = !inputArr[i][j];
        }
    }
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> inputArr(n,vector<int>(m));
    vector<vector<int>> targetArr(n,vector<int>(m));
    string tmp;
    for(int i=0;i<n;i++){
        cin>>tmp;
        for(int j=0;j<tmp.size();j++){
            inputArr[i][j] = (tmp[j]-'0');
        }
    }
    for(int i=0;i<n;i++){
        cin>>tmp;
        for(int j=0;j<tmp.size();j++){
            targetArr[i][j] = (tmp[j]-'0');
        }
    }
    
    int cnt = 0;

    for(int i=0;i<n-2;i++){
        for(int j=0;j<m-2;j++){
            if(inputArr[i][j] == targetArr[i][j]) continue;
            else{ // 다르면
                cal(inputArr, i, j);
                cnt++;
            }
        }
    }
    
    if(inputArr != targetArr){
        cnt = -1;
    }
    cout<<cnt<<endl;
}