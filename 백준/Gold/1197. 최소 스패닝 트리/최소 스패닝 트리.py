import heapq

v,e = map(int, input().split())
arr = []
visited =[]
answer = 0;
arr = [[] for _ in range(v+1)]
visited =[0 for _ in range(v+1)]

for _ in range(e):
    a,b,c = map(int,input().split())
    arr[a].append([c,b])
    arr[b].append([c,a])

heap = [[0,1]]
while heap:
    c,b = heapq.heappop(heap)
    if visited[b] !=0:
        continue
    else:
        visited[b]=1
        answer +=c 
        for tmp in arr[b]:
            heapq.heappush(heap,tmp)
print(answer)
