#include <iostream>
#include <stack>
#include <algorithm>


using namespace std;

int main(){
    string input, explosion;
    cin>>input>>explosion;
    int n = input.size();
    int m = explosion.size();
    stack<char> stack;

    for(int i=0;i<n;i++){
        stack.push(input[i]);
        if(stack.size()>=m){
            if(stack.top() == explosion[m-1]){
                // Stack의 top이 폭발 문자열 끝과 같다면
                string tmp = "";
                for(int j=0;j<m;j++){
                    tmp += stack.top();
                    stack.pop();
                }

                reverse(tmp.begin(),tmp.end());
                
                if(tmp != explosion){
                    for(int j=0;j<m;j++){
                        stack.push(tmp[j]);
                        
                    }
                }
            }
        }
    }

    if(stack.size()==0){
        cout<<"FRULA"<<endl;
    }else{
        string ans = "";
        while(!stack.empty()){
            ans += stack.top();
            stack.pop();

        }
        
        for(int i=ans.size()-1;i>=0;i--){
            cout<<ans[i];
        }
        cout<<endl;
    }
}