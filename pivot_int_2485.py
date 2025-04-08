def pivot_int(n):
    parent=[]
    for i in range(n):
        parent.append(i+1)
    for i in range(n):
        pivot=-1
        sum1=0
        sum2=0
        first=i+1
        second=len(parent)-(i+1)
        for one in range(first):
            sum1+=(parent[one])
        for two in range(len(parent)-1,i-1,-1):
            sum2+=(parent[two])
        if sum1==sum2:
            pivot=parent[i]
            break
    return pivot
print(pivot_int(4))
        