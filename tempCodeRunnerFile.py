def foo(addresses):
    ans = []
    for addr in addresses:
        res = "Neither"
        if '.' in addr:
            res = "IPv4"
            part = addr.split('.')
            
            if len(part) != 4:
                res = 'Neither'
            else:
                for p in part:
                    if len(p) > 3:
                        res = "Neither"
                        break
                    try:
                        n = int(p)
                        if n > 255 or n < 0:
                            res = "Neither"
                            break
                        if int(p) < 8:
                            pass
                        elif len(p) != len(str(int(p))):
                            res = "Neither"
                    except:
                        res = "Neither"
                        break

        if ':' in addr:
            res = "IPv6"
            part = addr.split(':')
            if addr.count(':') >= 8 or ((addr.count('::') == 0) and (addr.count(':') != 7)) or (addr.count("::") > 1):
                res = "Neither"
            else:
                char_list = '0123456789abcdef'
                for p in part:
                    if len(p) > 4:
                        res = 'Neither'
                        break
                    for c in p:
                        if c not in char_list:
                            res = "Neither"
                            break 
        
        ans.append(res)
    return ans

if __name__ == "__main__":
    # lst = [
    #     'ffff:ffff:ffff:ffff:ffff:ffff:ffff:fff',
    #     '255.255.255.255',
    #     '-200.0.0.0',
    #     '1:2:3:5',
    #     '000.012.255.255',
    #     '255.A12.255.255',
    #     '0.0.0.0',
    #     '2001:db8::ff00:0:8329',
    #     '.213.213.213.213',
    #     '::69g6',
    #     '666.666.23.23'
    # ]
    lst = []
    with open('input006.txt', 'r') as f:
        for l in f.readlines():
            # print(l)
            lst.append(l.strip())
    op = []
    with open('output006.txt', 'r') as f:
        for l in f.readlines():
            op.append(l.strip())

    l = foo(lst[1:])

    for addr, l1, l2 in zip(lst[1:], op, l):
        if l1 != l2:
            print(addr, l1, l2)      