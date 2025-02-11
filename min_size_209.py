def minSubArrayLen(target,nums):
    sum=l=0
    min_len=float('inf')
    for r in range(len(nums)):
        sum+=nums[r]
        while sum>=target:
            min_len=min(min_len,(r-l)+1)
            sum-=nums[l]
            l+=1
            
    if min_len==float('inf'):
        return 0
    return min_len

print(minSubArrayLen(7,[2,3,1,2,4,3]))
print(minSubArrayLen(11,[1,1,1,1,1,1,1,1]))
print(minSubArrayLen(11,[1,2,3,4,5]))
print(minSubArrayLen(4,[1,4,4]))
print(minSubArrayLen(15,[1,2,3,4,5]))