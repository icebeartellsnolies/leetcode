def median(arr):
    arr.sort()
    mid=len(arr)//2
    return arr[mid]

print(median([1,2,3,4,5]))