import numpy as np

def read_(name):
    with open(name, 'r') as f:
        n = int(f.readline())
        photos = {}
        for idx,line in enumerate(f):
            l = line.split()
            # print(l)
            if l[0] == 'V':
                continue
            photo = (l[0], l[1], l[2:])
            photos[idx] = photo
            if len(photos)>30000:
                break

    return n,photos

def check(v):
    return all(v)

def min_(*args):
    m = args[0]
    for a in args:
        m = min(a,m)
    return m

def find_next(v, data, s):
    score = -1
    next_ = -1
    # for i in v:
    #     print(i,end=" - ")
    # print("")
    for i,j in data.items():
        if v[i] or data[i][0]=='V':
            continue
        common = len(set(data[s][2]).intersection( set(data[i][2]) ) )
        cur_score = min_(len(data[s][2])-common, common, len(data[i][2])-common )
        if score < cur_score:
            score = cur_score
            next_ = i
    # print("Final score ", score, next_)
    return next_, score


def solve(n, data):
    best = 0
    best_arr = None
    flag = False
    for start in range(n):
        hue = []
        if data[start][0]=='V':
            continue
        else:
            flag = True
        visi = np.zeros(n)    
        sum = 0
        cur = start
        hue.append(cur)
        i = n-1
        visi[cur] = 1
        
        while i>0:
            if i%1000 == 0:
                print("MAnnnnnnnnnnnnnnnn")
            next_, score = find_next(visi, data, cur)
            if next_ == -1:
                break
            hue.append(next_)
            visi[next_] = 1
            sum += score
            cur = next_
            i-=1
        
        # assert check(visi)
        print("Node ", start, "score is ",sum)
        if sum > best:
            best = sum
            best_arr = hue
        if flag:
            break
    return best, best_arr
n , data = read_('b_lovely_landscapes.txt')
print("Len of data ", len(data))
# print(n)
# print(data)
xx, arr = solve(n, data)
with open("op_e.txt",'w') as f:
    f.write(str(len(arr)))
    f.write("\n")
    for xxx in arr:
        f.write(str(xxx))
        f.write("\n")