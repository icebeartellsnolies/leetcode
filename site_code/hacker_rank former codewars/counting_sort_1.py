def count_sort(arr):
    result = [0]*100
    for i in arr:
        result[i] += 1

print(count_sort([1,1,3,2,1]))