def log_dec(func):
    
    def wrapper(*args, **kwargs):
        print("Called with values: ")
        print("args: ", args)
        print("kwargs: ", kwargs)
        result = func(*args, **kwargs)
        print("Result: ", result)
        return result 
    
    return wrapper 


def count_mnmx(seq, si, ei, lbn=-1, rbn=-1):
    lmr = max([lbn, rbn])
    mn = 0
    mx = 0
    
    for i in range(si, ei):
        if seq[i]>lmr:
            mx += 1
        if seq[i]<lmr:
            mn += 1
    
    return [mn, mx]



def calculate_minimum_mana(seq, si, ei, x, k, y, lbn=-1, rbn=-1):
    minn, maxn = count_mnmx(seq, si, ei, lbn, rbn)
    length = ei-si
    
    if minn==0 and maxn==0:
        return 0
    
    if maxn>0 and length<k:
        return -1

    if x<=k*y:
        return (length//k)*x + (length%k)*y
    
    return (maxn>0)*x+(length-(k*(maxn>0)))*y


def main():
    intifier = lambda x: int(x)
    n,m = list(map(intifier, input().split(" ")))
    
    x,k,y = list(map(lambda x: int(x), input().split(" ")))
    
    a = list(map(intifier, input().split(" ")))
    b = list(map(intifier, input().split(" ")))
    
    ia = [-1 for i in range(n+1)]
    
    for i, ai in enumerate(a):
        ia[ai] = i    
    
    mana = 0
    prev_s = 0
    for indx, curr_s in enumerate(b):
        
        # print -1 if indx from b don't match
        if ia[prev_s]>ia[curr_s]:
            print(-1)
            return None
        
        lbn = prev_s
        rbn = curr_s if indx<m else -1
        
        si = ia[prev_s]+1 if prev_s!=0 else 0
        ei = ia[curr_s] if curr_s!=-1 else m
    
        tmp_mana = calculate_minimum_mana(a, si, ei, x, k, y, lbn, rbn)
        
        if tmp_mana < 0:
            print(-1)
            return None
        mana += tmp_mana
        prev_s = curr_s
    
    if ia[prev_s]<n-1:
        tmp_mana = calculate_minimum_mana(a, ia[prev_s]+1, n, x, k, y, prev_s, -1)
        
        if tmp_mana < 0:
            print(-1)
            return None
        mana += tmp_mana
    
    print(mana)
    return None
    

if __name__=="__main__":
    # ~ [main() for _ in range(5)]
    main()

# 5
"""
6 2
2 1 1
4 6 5 3 2 1
4 2

"""

# 6
"""
5 3
2 1 2
5 2 4 1 3    
5 3

"""

# 4
"""
5 2
2 1 1
4 5 3 2 1
4 1

"""

# -1
"""
7 3
3 2 4
5 1 3 6 7 4 2
1 7 4

"""


# 10
"""
8 3
3 2 4
5 8 1 3 6 7 4 2
1 7 4

"""
