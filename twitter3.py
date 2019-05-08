n = int(input())
m = int(input())

l1 = []
l2 = []

for _ in range(m):
    x = int(input())
    l1.append(x)

for _ in range(m):
    x = int(input())
    l2.append(x)

vals = [-1]

for _ in range(n):
    x = int(input())
    vals.append(x)

adj_list = []

for i in range(n+1):
    adj_list.append([])

for i in range(m):
    adj_list[l1[i]].append(l2[i])
    adj_list[l2[i]].append(l1[i])

is_prime = [False]*(max(vals)+1)

for i in range(n):
    flag = True
    for j in range(2,vals[i]):
        if (j * j > vals[i]):
            break
        if (vals[i] % j == 0):
            flag = False
            break
    is_prime[ vals[i] ] = flag 
is_prime[1] = False

cnt = [0]*(n+1)
visi = [0]*(n+1)

def dfs(s):
    # print(vals[s])
    if visi[s]:
        return 0
    visi[s] = 1
    cnt[s] += is_prime[vals[s]]
    for i in adj_list[s]:
         cnt[s] += dfs(i)
    return cnt[s]

for i in range(1,n): 
    if(not visi[i]):
        cnt[i] = dfs(i)

q = int(input())
for _ in range(q):
    x = int(input())
    print(cnt[x])

    
# print(cnt)
# print(is_prime)
# print(adj_list)
