import sys, heapq
input = sys.stdin.readline

n,m = map(int,input().split())
visited = [0 for _ in range(n+1)]
arr = [[] for _ in range(n+1)]
heap =[(0,1)]
answer = 0
maxCost = 0
for i in range(m):
    a,b,c = map(int,input().split())
    arr[a].append((c,b))
    arr[b].append((c,a))
while (heap):
    c,b=heapq.heappop(heap)
    if visited[b]==0:
        visited[b]=1
        if (c>maxCost):
            maxCost = c
        answer += c
        for nextc,nextb in arr[b]:
            if visited[nextb]==0:
                heapq.heappush(heap,(nextc,nextb))

print(answer-maxCost)