t = int(input())
for _ in range(t):
    n = int(input())
    l1 = []
    l2 = []
    l1 = list(map(int,input().split()))
    l2 = list(map(int,input().split()))
    l3 = [i-j for i,j in zip(l1, l2)]
    i = 0
    j = len(l3) - 1
    while i < len(l3) and l3[i] == 0:
        i += 1
    while j>=0 and l3[j]==0:
        j -= 1
    if j == -1 or (len(set(l3[i:j+1])) == 1 and l3[i]<0):
        print("YES")
    else:
        print("NO")