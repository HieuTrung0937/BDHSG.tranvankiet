def printlist(a):
    for i in range(len(a)):
        for j in range(len(a[i])):
            print(a[i][j], end = " ")
        print()



def chuyen_vi(a, n):
    b = []
    for line in range(n):
        b.append([])
        for row in range(len(a)):
            b[line].append(0)
    for i in range(len(a)):
        for j in range(len(a[0])):
            b[j][i] = a[i][j]

    return b




a = [[1,2,4,6],[4,7,8,9]]
n = 4  
m =chuyen_vi(a,n)
print(m)
printlist(a)
printlist(m)
