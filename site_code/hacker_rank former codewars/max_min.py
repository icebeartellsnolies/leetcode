def difference(k,arr):
    arr.sort()
    pointer1=0
    to_return=float('inf')
    pointer2=k-1
    while pointer2 < len(arr):
        difference = arr[pointer2] - arr[pointer1]
        if difference<to_return:
            to_return = difference
        pointer1 += 1
        pointer2 += 1
    return to_return

print(difference(3,[100,200,300,350,400,401,402]))