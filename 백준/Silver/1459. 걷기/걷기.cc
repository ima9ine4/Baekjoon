#include <iostream>
using namespace std;

int main(){
    int X,Y,w,s;
    cin>>X>>Y>>w>>s;
    int a = 0; int b = 0; //현재 좌표
    long long ww = 0; // 쭉 몇 번 움직였는지
    long long ss = 0; // 대각선으로 몇 번 움직였는지

    if(X==0){ //가로로만 가면 될 때
        if(2*s < 2*w){ // 왔다갔다 하는게 더 빠르면?
            ss += (Y/2)*2; //갈 수 있는만큼은 왔다갔다 해서 가기!
            if(Y%2==1) ww += 1; // 홀수면 마지막 한 번은 w으로 가기
        }else{ // w로만 가는게 더 빠르면?
            ww += Y; // 쭉 이동
        }
    }else if(Y==0){ // 세로로만 가면 될 때
        if(2*s < 2*w){ // 왔다갔다 하는게 더 빠르면?
            ss += (X/2)*2; // 갈 수 있는만큼은 왔다갔다 해서 가기!
            if(X%2==1) ww += 1; // 홀수면 마지막 한 번은 s로 가기
        }else{ // w로만 가는게 더 빠르면?
            ww += X; // 쭉 이동
        }
    }else{ // 대각선 이동도 필요할 때
        if(s < 2*w){ // 대각선 이동이 가로+세로 보다 빠르면?
            ss += min(X,Y);
            X -= ss; Y -= ss; //이동해야 하는 거리로 업데이트
            if(2*s < 2*w){ //쭉가는 것보다 왔다갔다가 빠르면?
                ss += (Y/2 + X/2)*2; // 갈 수 있는 만큼은 왔다갔다하기
                if(X%2==1) ww += 1; // 남은 건 그냥 가기
                if(Y%2==1) ww += 1; // 남은 건 그냥 가기
            }else{ // 그건 아니면? 쭉가기
                ww += (X+Y);
            }
        }else{ // 대각선 이동이 필요 없을 때
            ww += X+Y;
        }

    }

    long long www = ww*w;
    long long sss = ss*s;
    long long ans = www+sss;
    cout<<ans<<endl;
}