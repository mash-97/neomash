
def main():
    Intifier = lambda x: int(x)
    n,m = list(map(Intifier, input().split(" ")))
    discs = list(map(Intifier, input().split(" ")))
    
    # initialize towers as dit of a dit
    towers = {}
    for i in range(1,m+1):
        towers[i] = {}
    
    # intialize towers with connetions themselves from discs
    # and count total connetions
    total_connections = 0
    ptn = discs[0]
    for ctn in discs:
    
        if ptn != ctn:
            total_connections += 1
            if ptn in towers:
                if ctn in towers[ptn]:
                    towers[ptn][ctn] += 1
                else:
                    towers[ptn][ctn] = 1
            else:
                towers[ptn] = {}
                towers[ptn][ctn] = 1
            
            if ctn in towers:
                if not ptn in towers[ctn]:
                    towers[ctn][ptn] = 0
            else:
                towers[ctn] = {}
                towers[ctn][ptn] = 0
            
            ptn = ctn
    
    
    print(total_connections)
    for i in range(m-1):
        ai, bi = list(map(Intifier, input().split(" ")))
        connections = 0
        
        if ai in towers[bi]:
            connections += towers[bi][ai]
            
        if bi in towers[ai]:
            connections += towers[ai][bi]
        
        for t in towers[bi]:
            if t in towers[ai]:
                towers[ai][t] += towers[bi][t]
            else:
                towers[ai][t] = towers[bi][t]
            
            if bi in towers[t]:
                if ai in towers[t]:
                    towers[t][ai] += towers[t][bi]
                else:
                    towers[t][ai] = towers[t][bi]
        
        
        total_connections -= connections
        print(total_connections)
        
        

if __name__=="__main__":
    main()
