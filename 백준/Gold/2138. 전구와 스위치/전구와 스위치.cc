#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void press(int n, int idx, vector<int>& input){
    if(idx == 0){
        input[idx] = !input[idx];
        input[idx+1] = !input[idx+1];
    }else if(idx == n-1){
        input[idx-1] = !input[idx-1];
        input[idx] = !input[idx];
    }else{
        input[idx-1] = !input[idx-1];
        input[idx] = !input[idx];
        input[idx+1] = !input[idx+1];
    }
}

int solve1(int n, vector<int> input, vector<int>& target){
    //0번째, 1번째 버튼 누르지 않음
    int cnt = 0;
    for(int i=2;i<n-1;i++){
        if(input[i-1]!=target[i-1]){
            press(n, i, input);
            cnt++;
        }
    }
    if(input != target){
        return -1;
    }
    return cnt;
}

int solve2(int n, vector<int> input, vector<int>& target){
    //0번째, 1번째 누름
    press(n,0,input);
    press(n,1,input);
    int cnt = 2;
    for(int i=2;i<n;i++){
        if(input[i-1]!=target[i-1]){
            press(n, i, input);
            cnt++;
        }
    }
    if(input != target){
        return -1;
    }
    return cnt;
}

int solve3(int n, vector<int> input, vector<int>& target){
    //0번째만 누름
    press(n,0,input);
    int cnt = 1;
    for(int i=2;i<n;i++){
        if(input[i-1]!=target[i-1]){
            press(n, i, input);
            cnt++;
        }
    }
    if(input != target){
        return -1;
    }
    return cnt;
}

int solve4(int n, vector<int> input, vector<int>& target){
    //1번째만 누름
    press(n,1,input);
    int cnt = 1;
    for(int i=2;i<n;i++){
        if(input[i-1]!=target[i-1]){
            press(n, i, input);
            cnt++;
        }
    }
    if(input != target){
        return -1;
    }
    return cnt;
}

int main(){
    int n; cin>>n;
    string a,b;
    cin>>a>>b;
    vector<int> input(n,0);
    vector<int> target(n,0);

    for(int i=0;i<n;i++){
        input[i]=a[i]-'0';
        target[i]=b[i]-'0';
    }

    int ans;
    if(input[0]==target[0]){
        int tmp1 = solve1(n,input,target);
        int tmp2 = solve2(n,input,target);
        if(tmp1 == -1 && tmp2 == -1){
            ans = -1;
        }else if(tmp1 == -1){
            ans = tmp2;
        }else if(tmp2 == -1){
            ans = tmp1;
        }else{
            ans = min(tmp1, tmp2);
        }
    }else{
        int tmp1 = solve3(n,input,target);
        int tmp2 = solve4(n,input,target);
        if(tmp1 == -1 && tmp2 == -1){
            ans = -1;
        }else if(tmp1 == -1){
            ans = tmp2;
        }else if(tmp2 == -1){
            ans = tmp1;
        }else{
            ans = min(tmp1, tmp2);
        }
    }


    cout<<ans<<endl;
}