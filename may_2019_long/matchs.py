fl = 0
def foo(i, j, player):
    global fl    
    if fl:
        print("FOo-->",i,j,player)
    if i==0 or j==0:
        return 1-player
    
    if i == j or i == 1 or j == 1:
        return player
    
    if i%j == 0 or j%i == 0:
        return player
    
    if dp[i][j] != -1:
        return dp[i][j] ^ player
    
    ret = []
    
    for f in range(1,i+1):
        if j%f==0:
            ret.append(foo(i-f, j, 1-player))
            
    for f in range(1,j+1):
        if i%f==0:
            ret.append(foo(i, j-f, 1-player))
    
    if player:
        return max(ret)
    else:
        return min(ret)
    
dp = []

for i in range(1000):
    dp.append([-1]*1000)
    
for i in range(1,156):
    for j in range(1,48):
        if i==155 and j==47:
            fl=1
        dp[i][j] = foo(i, j, 0)
        print("-->",i,j,dp[i][j])

