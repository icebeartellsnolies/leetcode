arr_len, set_len=map(int,input().split())
arr=list(map(int,input().split()))
set_a=list(map(int,input().split()))
set_b=list(map(int,input().split()))
happiness=0
for elements in arr:
    if elements in set_a:
        happiness+=1
    elif elements in set_b:
        happiness+=-1
print(happiness)