import sys, heapq
input = sys.stdin.readline
n = int(input())
heap = []
for i in range(n):
    tmp = int(input())
    if (tmp!=0):
        heapq.heappush(heap,tmp)
    elif (tmp==0):
        if not heap:
            print(0)
        else: print(heapq.heappop(heap))