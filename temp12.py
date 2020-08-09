import itertools

def foo(l):
    edge = set()
    n = len(l)
    for i in range(n):
        for j in range(i-1,-1,-1):
            if l[j] > l[i]:
                edge.add(tuple(sorted((i,j))))
                break
        for j in range(i+1, n):
            if l[j] > l[i]:
                edge.add(tuple(sorted((i,j))))
                break
    # print(l)
    # print(edge)
    # print("-"*30)
    if len(edge) < n:
        print(l)
        print(edge)
    return len(edge) >= len(l)

ans = 0
for l in itertools.permutations([1,2,3,4]):
    ans += foo(l)

print(ans)

# n = int(input())
 
# x = 1
# m = 1000000007
# for i in range(1, n+1):
#     x *= i
#     x %= m
 
# y = 1
# for i in range(n-1):
#     y *= 2
#     y %= m

# if x - y < 0:
#     print(x - y + m)
# else:
#     print(x - y)