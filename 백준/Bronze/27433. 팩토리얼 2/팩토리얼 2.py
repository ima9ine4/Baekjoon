n = int(input());
def recur(a): #6
    if (a==0)or(a==1):
        return 1
    else:
        return a*recur(a-1)
print(recur(n))