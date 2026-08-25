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










# def gioithieu():
#     print("Hello")

# def gioithieu111():
#     return 0

# def [ten ham](<kieu du lieu>, <kieu du lieu>,....):
#     <khoi lenh thuc thi>
#     return <gia tri tra ve>

def kiemtra(a, x):
    n = len(a)
    l = 0
    r = n - 1
    while l <= r:
        m = int((l + r)/2)
        if a[m] == x:
            return True
        elif x < a[m]:
            r = m - 1
        else:
            l = m + 1
    return False
a = [1 ,3 ,4, 7 ,12 ,16 ,18]
# n = len(a)
x = 8

print(kiemtra(a,x))

