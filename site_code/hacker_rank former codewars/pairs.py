def pairs(k, arr):
    occurences=0
    for i in range(len(arr)):
        for j in range(i,len(arr)):
            if abs(arr[i]-arr[j])==k:
                occurences+=1
    return occurences

print(pairs(2,[1, 5, 3, 4, 2]))
# modified:
[1,2,3,4,5]
def pairs(k, arr):
    occurences=0
    arr.sort()
    arr_set=set(arr)
    for i in arr:
        to_find=i+k
        if to_find in arr_set:
            occurences+=1
    return occurences
print(pairs(2,[1, 5, 3, 4, 2]))