def maxAscendingSum(nums):
    l = 0
    sum = nums[l]
    max_sum=sum
    for r in range(1, len(nums)):
        if nums[r] > nums[r - 1]:
            sum += nums[r]
        else:
            l = r
            max_sum=max(sum,max_sum)
            sum = nums[l]
            max_sum=max(sum,max_sum)

    return max(sum,max_sum)
print(maxAscendingSum([12,17,15,13,10,11,12]))