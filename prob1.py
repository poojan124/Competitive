def dfs(curf, pos, l, dp, visi):
    if visi.get(l[pos], 0) == 1:
        return 0
    
    if curf < 0:
        return 0

    if pos == len(l) - 1:
        return 1

    visi[l[pos]] = 1

    ans = 0
    for i in range(pos+1, len(l)):
        ans += dfs(curf - abs(l[pos] - l[i]), i, l, dp, visi)
        ans = ans%1000000007
        
    if ans == 0:
        ans = 1

    visi[l[pos]] = 0
    dp[pos][curf] = ans

    return dp[pos][curf]

def foo(n, f, l):
    dp = [[0]*(f+1) for _ in range(n)]
    visi = dict()
    _ = dfs(f, 0, l, dp, visi)
    return dp[0][f]

if __name__ == "__main__":
    n = 5
    f = 7
    l = [1, 3, 6, 2,4]
    print(foo(n, f, l))