arr = []
for r in range(5):
    n = int(input())
    arr.append(n)
lowest=arr[0]
for i in range(5):
    j=i+1
    while j<5:
        if arr[j]<arr[i]:
            lowest=arr[j]
            arr[j]=arr[i]
            arr[i]=lowest
        j=j+1
l=len(arr)
largest=arr[l-1]
r=l-1
while r>=0:
    if arr[r]<largest:
        break
    else:
        r=r-1
print(arr[r])