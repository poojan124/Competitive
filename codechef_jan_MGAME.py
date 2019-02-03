from math import ceil
t = int(input())
for _ in range(t):
    n,p = map(int,input().split())
    if n<=2:
        print(p*p*p)
    else:
        ans = 0
        M = ceil(n/2.0)-1
        ans += (p-M)*(p-M)
        if p>n:
            ans += (p-n)*(p-n)
            ans += (p-n)*(p-M)
        print(ans)

