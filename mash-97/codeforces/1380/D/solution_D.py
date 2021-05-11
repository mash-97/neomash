PINF = float("inf")
NINF = -PINF

def does_maxn_exist(seq, si, ei, lbn=-1, rbn=-1):
    lmr = max([lbn, rbn])
    
    for i in range(si, ei):
        if seq[i] > lmr:
            return True
    
    return False

        
def does_lkmin_exist(seq, si, ei, lk, lbn=-1, rbn=-1):
    lmr = max([lbn, rbn])
    count = 0
    
    for i in range(si, ei):
        if seq[i] < lmr:
            count += 1
    
    if count >= lk:
        return True
    return False

def get_energy_by_xm(seq, si, ei, x, k, y, lbn=-1, rbn=-1):
    l = (ei-si)
    if l < k:
        return PINF
    elif (l%k)>0 and not does_lkmin_exist(seq, si, ei, l%k, lbn, rbn):
        return PINF
    
    return (l//k)*x + (l%k)*y


def count_mnmx(seq, si, ei, x, k, y, lbn=-1, rbn=-1):
    mn = 0
    mx = 0
    lmr = max([lbn, rbn])
    
    for i in range(si, ei):
        if seq[i]>lmr:
            mx += 1
        if seq[i]<lmr:
            mn += 1
    return [mn, mx]


def get_energy_by_ymxm(seq, si, ei, x, k, y, lbn=-1, rbn=-1):
    mn,mx = count_mnmx(seq, si, ei, x, k, y, lbn, rbn)
    if mx!=0 and mx%k!=0:
        inc = ((mx+k)-(mx%k)) - mx
        if inc > mn:
            return PINF
        mx += inc
        mn -= inc
    
    return (mx//k)*x + mn*y


def get_energy_by_ym(seq, si, ei, y, lbn=-1, rbn=-1):
    if does_maxn_exist(seq, si, ei, lbn, rbn):
        return PINF
    return (ei-si)*y


def get_min_energy(seq, si, ei, x, k, y, lbn=-1, rbn=-1):
    exm = get_energy_by_xm(seq, si, ei, x, k, y, lbn, rbn)
    # ~ print("si: {}, ei: {}, exm: {}".format(si, ei, exm))
    eymxm = get_energy_by_ymxm(seq, si, ei, x, k, y, lbn, rbn)
    
    eym = get_energy_by_ym(seq, si, ei, y, lbn, rbn)
    # ~ print("si: {}, ei: {}, eym: {}".format(si, ei, eym))
    # ~ print("exm: {}, eymxm: {}, eym: {}".format(exm, eymxm, eym))
    
    if(min([exm, eym, eymxm])==PINF):
        return -1
    return min([exm, eym, eymxm])


# ~ def check_bseq(a, b, m, ia):
    # ~ i = 1
    # ~ while i<m:
        # ~ if ia[b[i-1]] > ia[b[i]]:
            # ~ return False
        # ~ i += 1
    # ~ return True


def main():
    intifier = lambda x: int(x)
    n,m = list(map(intifier, input().split(" ")))
    
    x,k,y = list(map(lambda x: int(x), input().split(" ")))
    
    a = list(map(intifier, input().split(" ")))
    b = list(map(intifier, input().split(" ")))
    
    ia = [-1 for i in range(n+1)]
    
    for i, ai in enumerate(a):
        ia[ai] = i    
    
    
    if n<m:
        print("-1")
        return None
    
    indx = 1
    energy = 0
    
    if ia[b[0]] > 0:
        tmp_e = get_min_energy(a, 0, ia[b[0]], x, k, y, -1, b[0])
        if tmp_e==-1:
            print("-1")
            return None
        energy+=tmp_e
        # ~ print("0-{}: {}".format(ia[b[0]], tmp_e))
    
    while indx < m:
        if ia[b[indx-1]] < ia[b[indx]]:
            if (ia[b[indx]] - ia[b[indx-1]] == 1):
                energy += 0 
            else:
                tmp_e = get_min_energy(a, ia[b[indx-1]]+1, ia[b[indx]], x, k, y, b[indx-1], b[indx])
            
                if tmp_e==-1:
                    print("-1")
                    return None
                energy+=tmp_e
        
        else:
            print("-1")
            return None
        # ~ print("%s-%s: %s"%(indx-1, indx, tmp_e))
        indx += 1
    
    if ia[b[m-1]] < n-1:
        tmp_e = get_min_energy(a, ia[b[m-1]]+1, n, x, k, y, b[m-1], -1)
        if tmp_e==-1:
            print("-1")
            return None
        energy+=tmp_e
        # ~ print("%s-..: %s"%(m-1, tmp_e))
    print(energy)



if __name__=="__main__":
    main()


"""
5 3
2 1 2
5 2 8 1 3    
5 3
"""

"""
5 2
2 1 1
4 5 3 2 1
4 1

"""
