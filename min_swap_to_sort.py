def foo(l):

    l = [x%2 for x in l]
    p1 = 0
    p2 = len(l) - 1
    ans = 0
    while p2 > p1:
        while (p1 < len(l)) and (l[p1] != 1) :
            p1 += 1
        while (p2 >= 0) and (l[p2] != 0):
            p2 -= 1
        if p1 > p2:
            break
        ans += 1
        l[p1] = 0
        l[p2] = 1
        p1 += 1
        p2 -= 1
    
    return ans

if __name__ == "__main__":
    print(foo([8,5,11,4,6]))
    print(foo([13,10,21,20]))