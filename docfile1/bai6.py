fi = open('docfile1/bai6.inp')
fo = open('docfile1/bai6.out','w')

n , k= map(int,fi.readline().split())
a = list(map(int,fi.read().split()))
def tim(n,k,a):
    count = 0
    if n not in a:
        return -1
    for i in a:
        if i == n:
            count +=1
    return f'{count} {n}'

fo.write(tim(n,k,a))
fi.close()
fo.close()