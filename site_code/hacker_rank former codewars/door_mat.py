def door_mat(m):
    n=m*3
    first=int(((n-1)/2)-1)
    arr_l=m//2
    a=[None]*(arr_l)
    i=0
    for r in range(arr_l):
        f=('-'*(first-i))
        a[r]=f+('.|.'*r)+('.|.'*(r+1))+f
        print(a[r])
        i=i+3
    print('-'*(int((n-7)/2)),end='')
    print('Welcome',end='')
    print('-'*(int((n-7)/2))) 
    backwards=arr_l-1
    i=arr_l
    for r in range(arr_l):
            print(a[backwards])
            backwards=backwards-1
door_mat(35)