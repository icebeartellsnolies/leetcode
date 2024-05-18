def balanced_sums(arr):
    if len(arr) == 0:
        return 'No'
    arr.insert(0,0)
    arr.append(0)
    for index in range(1,len(arr)-1):
        half1 = arr[:index]
        half2 = arr[index+1:]
        sum1 = sum(half1)
        sum2 = sum(half2)
        if sum1 == sum2:
            return 'Yes'
    return 'No'        
# print(balanced_sums([1,1,4,1,1]))
# print(balanced_sums([1,1,4,1,1]))
# print(balanced_sums([5,6,8,11]))
# print(balanced_sums([1]))
# print(balanced_sums([1,2,3]))
# print(balanced_sums([1,2,3,3]))
# print(balanced_sums([0,0,2,0]))
# print(balanced_sums([1,1,4,1,1]))
# prefix_sum=[1,2,6,7,8]
def balanced_sums(arr):
    total_sum = sum(arr)
    left_sum = 0
    for num in arr:
        # Subtract the current element from the total sum to get the right sum
        total_sum -= num
        # If left sum equals the right sum, return 'Yes'
        if left_sum == total_sum:
            return 'Yes'
        # Add the current element to the left sum
        left_sum += num
    
    return 'No'
# print(balanced_sums([1,1,4,1,1]))
# print(balanced_sums([0,0,2,0]))
# print(balanced_sums([2,0,0,0]))
print(balanced_sums([1,2,3]))