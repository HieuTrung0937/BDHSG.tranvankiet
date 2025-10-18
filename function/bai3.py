from itertools import combinations
 
def C(n,k):
    for i in combinations(n,k):
        print(i)
# def A(n,k):

a = [1,2,3,4,5]
C(a,2)