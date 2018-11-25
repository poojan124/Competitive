n = int(input())
ans = list(map(int,input().split()))[1:]
for _ in range(n-1):
    k = list(map(int,input().split()))
    em = [i for i in k[1:] if i in ans]
    ans = em
for X in ans:
    print(X,end=" ")