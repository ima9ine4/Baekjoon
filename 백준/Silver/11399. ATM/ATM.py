n=int(input())
time=list(map(int,input().split()))
time.sort()
ret=0
tmp=0
ans=0
for i in time:
    tmp+=i
    ret=tmp
    ans+=ret
print(ans)