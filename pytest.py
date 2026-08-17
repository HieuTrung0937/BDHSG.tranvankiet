# if dieu kien:
# else:
# elif dieu kien:
# True False
# and or not
# str, int, float, bool
# for <bien> in range(<so bat dau>, <buoc nhay>, <ket thuc>):
#     khoi len
# for i in range(5+1):
#     print(i)
# while i < 5:
#     i+=1
# a = [2, 4,6,8,10]
# a = [2, "a", 9.1, "abc"]
# a.pop(2)
# for i in a:
#     print(i, end = " ")
# # print(max(a))
a = [1 ,3 ,4, 7 ,12 ,16 ,18]
n = len(a)
x = 777

l = 0
r = n - 1
CoTrongMang = False
while l <= r:
    m = int((l + r)/2)
    if a[m] == x:
        CoTrongMang = True
        break
    elif x < a[m]:
        r = m - 1
    else:
        l = m + 1
if(CoTrongMang): 
    print('Co!')
else:
    print("Khong co trong mang!")