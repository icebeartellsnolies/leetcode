def longestNiceSubarray(nums):
    l=0
    r=0
    curr_sum=0
    xor_sum=0
    max_len=0
    while r<len(nums):
        curr_sum+=nums[r]
        xor_sum^=nums[r]
        while curr_sum!=xor_sum:
            curr_sum-=nums[l]
            xor_sum^=nums[l]
            l+=1
        length=r-l+1
        max_len=max(length,max_len)
        r+=1
    return max_len

# print(longestNiceSubarray([1,3,8,48,10]))
print(longestNiceSubarray([3,1,5,11,13]))