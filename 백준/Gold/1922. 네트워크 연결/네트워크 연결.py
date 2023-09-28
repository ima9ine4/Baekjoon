import heapq

n = int(input())
m = int(input())
visited =[ 0 for _ in range(n+1)]
arr = [ [] for _ in range(n+1)]
heap = [[0,1]]
answer = 0
for i in range(m):
    a,b,c = map(int, input().split())
    arr[a].append([c,b])
    arr[b].append([c,a])
while (heap):
    c,b = heapq.heappop(heap)
    if visited[b]!=0:
        continue
    else:
        visited[b]=1
        answer +=c
        for j in arr[b]:
            heapq.heappush(heap,j)

print(answer)