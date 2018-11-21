def mystery(letter):
    cnt = 0
    n = len(letter)
    for i in range(0,int(n/2)):
        cnt += abs(ord(letter[i])-ord(letter[n-i-1]))
    return cnt

def foo(s):
    return sum([abs(ord(s[i]) - ord(s[len(s)-i-1])) for i in range(int(len(s)/2))])

t = int(input())
for _ in range(t):
    s = input()
    print(foo(s)) 