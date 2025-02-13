#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    sort(citations.begin(), citations.end());
    int n = citations.size();
    for(int i=0;i<=citations[n-1];i++){
        int cnt = 0;
        for(int j=0;j<citations.size();j++){
            if(i<=citations[j]){
                cnt++;
            }
        }
        cout<<"cnt= "<<cnt<<endl;
        cout<<"i= "<<i<<endl;
        if(cnt>=i){
            answer = i;
        }
    }
    return answer;
    
}