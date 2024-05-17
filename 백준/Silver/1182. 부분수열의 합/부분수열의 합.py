from itertools import combinations
n,s =map(int,input().split())
lst = list(map(int,input().split()))
cnt = 0
for i in range(1,n+1):
    tmp = list(combinations(lst,i))
    for j in tmp:
        if sum(j)==s:
            cnt += 1
print(cnt)