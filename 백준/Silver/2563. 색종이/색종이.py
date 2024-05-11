t=int(input())
coord=[[0 for i in range(101)] for j in range(101)]
for _ in range(t):
    h,v=map(int,input().split())
    for i in range(h,h+10):
        for j in range(v,v+10):
            coord[i][j]=1
cnt=0
for k in coord:
    cnt+=k.count(1)
print(cnt)