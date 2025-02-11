def summary(nums):
    pointer1 = 0
    ans = []
    
    while pointer1 < len(nums):
        start = nums[pointer1]
        while pointer1 + 1< len(nums) and nums[pointer1+1] - nums[pointer1] == 1:
            pointer1 += 1
        if start == nums[pointer1]:
            ans.append(str(nums[pointer1])) 
        else:
            ans.append(f'{start}->{nums[pointer1]}')

        pointer1 += 1
    return ans

print(summary([0,1,2,4,5,7]))
print(summary([0,2,3,4,6,8,9]))
