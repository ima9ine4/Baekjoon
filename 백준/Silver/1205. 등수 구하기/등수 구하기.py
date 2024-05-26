n,taesu,p=map(int,input().split())
if n==0:
    print(1)
else:
    if n>=p: #주어진 점수들이 랭킹개수보다 더 많거나 같을 때
        scores = list(map(int, input().split()))
        ranking = [0]*n
        for i in range(n):
            ranking[i] = scores[i]

        if ranking[-1]>=taesu:
            print(-1)

        else:
            ranking.append(taesu)
            ranking.sort(reverse=True)
            rank=1
            for i in range(len(ranking) - 1):
                if ranking[i] == taesu:
                    print(rank)
                    break
                else:
                    rank += 1

    else: #랭킹 개수가 주어진 점수들보다 더 많을 때
        ranking = list(map(int, input().split()))
        ranking.append(taesu)
        ranking.sort(reverse=True)
        rank=1
        for i in range(len(ranking)):
            if ranking[i] == taesu:
                print(rank)
                break
            else:
                rank += 1