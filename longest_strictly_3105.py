def longestMonotonicSubarray(nums):
    inc_size=1
    l=0
    for r in range(1,len(nums)):
        if(nums[r]>nums[r-1]):
            size=(r-l)+1
            inc_size=max(size,inc_size)
        else:
            l=r

    dec_size=1
    l=0
    for r in range(1,len(nums)):
        if(nums[r]<nums[r-1]):
            size=(r-l)+1
            inc_size=max(size,inc_size)
        else:
            l=r
    return max(dec_size, inc_size)


print(longestMonotonicSubarray([1,4,3,3,2]))
print(longestMonotonicSubarray([3,3,3,3]))
print(longestMonotonicSubarray([3,2,1]))

