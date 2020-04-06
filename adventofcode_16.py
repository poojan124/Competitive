import itertools
from math import ceil

start = list(map(int, '12345678'.split()))
seq = [0,1,0,-1]

def phase(x, lst):
    ret = []
    tmp = list(itertools.chain.from_iterable(itertools.repeat(i, x) for i in seq))
    tmp = list(itertools.chain.from_iterable(itertools.repeat(tmp, ceil(len(start) / len(tmp) + 1))))[1:]
    for a,b in zip(lst, tmp):
        ret.append(a * b)
    return 

def mat():
    ret = []
    for i in range(1, len(start) + 1):
        
    tmp = list(itertools.chain.from_iterable(itertools.repeat(i, x) for i in seq))
    tmp = list(itertools.chain.from_iterable(itertools.repeat(tmp, ceil(len(start) / len(tmp) + 1))))[1:]
    