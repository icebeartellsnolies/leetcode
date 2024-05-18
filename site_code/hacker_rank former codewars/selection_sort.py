a=[1,4,0,8,9]
n=len(a)
lowest=a[0]
for i in range(n):
    j=i+1
    while j<n:
        if a[j]<a[i]:
            lowest=a[j]
            a[j]=a[i]
            a[i]=lowest
        j=j+1
print(a)