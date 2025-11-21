def bfs(g,s):
    tham=[s]
    hdoi=[s]
    n=0
    while hdoi:
        u=hdoi.pop(0)
        n+=1
        for i in g[u]:
            if i not in tham:  
                tham.append(i)
                hdoi.append(i)
    return n
with open('bdhsg/DFS_and_BFS/lienthong/lienthong2.inp') as f:
    a,b= list(map(int,f.readline().split()))
    c=[]
    for i in f.read().split('\n'):
        tam=i.split()
        c.append([int(tam[0]),int(tam[1])])
d=[[] for i in range(a+1)]
for u,v in c:
    d[u].append(v)
def ktra():
    for i in range(a):
        if bfs(d,i)==a:
            t=True
            f=True
            for l in range(a):
                if bfs(d,l)!=a:
                    t=False
            if t==f:
                return 'ltm'
        elif bfs(d,i)!=a:
            for j in range(a):
                if bfs(d,j)==a:
                    return   'lty'      
        
    return 'klt'
with open('bdhsg/DFS_and_BFS/lienthong/lienthong2.out','w') as f:
    f.write(ktra())