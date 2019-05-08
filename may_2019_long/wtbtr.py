import math

def rotate(x, y):
    return ( x * math.cos(math.pi/4) - y * math.sin(math.pi/4) , 
             x * math.sin(math.pi/4) + y * math.cos(math.pi/4) )

def min_d(a):
    x = sorted(a, key = lambda x : x[0])
    y = sorted(a, key = lambda x : x[1])
    return min([b[0]-a[0] for a,b in zip(x[:-1],x[1:])] + [b[1]-a[1] for a,b in zip(y[:-1],y[1:])])/math.sqrt(2)

for _ in range(int(input())):
    l = []
    for it in range(int(input())):
        x, y = map(int, input().split())
        l.append((x, y))
    l1 = list(map(lambda x:rotate(*x), l))
    print("%0.15f" % min_d(l1))
