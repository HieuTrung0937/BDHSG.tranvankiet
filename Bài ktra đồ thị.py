def bfs(graph,u):
    tham=[u]
    hdoi=[u]
    while hdoi:
        tam=hdoi.pop(0)
        for i in graph[tam]:
            if i not in tham:
                tham.append(i)
                hdoi.append(i)
    return len(tham)
def ktra(dinh,canh,n):
    if ltm(dinh,n): return 'Liên thông mạnh'
    else:    
        dinh_vh=[[] for __ in range(n+1)]
        for u,v in canh:
            dinh_vh[u].append(v)
            dinh_vh[v].append(u)
        if bfs(dinh_vh,0)==n: return 'Liên thông yếu'
        else: return 'Không liên thông'
def ltm(dinh,n):
    for i in range(n):
        if bfs(dinh,i)!=n: return False
    return True
with open('bdhsg/DFS_and_BFS/lienthong/lienthong2.inp') as fi:
    n,m=map(int,fi.readline().split())
    canh=[]
    for i in fi.read().split('\n'):
        tam=i.split()
        canh.append([int(tam[0]),int(tam[1])])
dinh=[[] for __ in range(n+1)]
for u,v in canh:
    dinh[u].append(v)
with open('bdhsg/DFS_and_BFS/lienthong/lienthong2.out','w',encoding='utf_8') as fo:
    fo.write(ktra(dinh,canh,n))