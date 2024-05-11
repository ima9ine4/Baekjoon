t=int(input())
coordinate=[[r for r in range(1,101)] for p in range(1,101)]
for _ in range(t):
    h,v=map(int,input().split())
    for j in range(v,v+10):
        for i in range(h,h+10):
            coordinate[j][i]=0
ret=0
for i in range(len(coordinate)):
    cnt=0
    cnt=coordinate[i].count(0)
    ret+=cnt
print(ret)