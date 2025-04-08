def find_132(nums):
    if len(nums)<3:
        return False
    i,j,k=0,1,2
    while(k<len(nums)):
        if nums[j]>nums[k] and nums[j]>nums[i] and nums[k]>nums[i]:
            return True
        i+=1
        j+=1
        k+=1
    return False

# print(find_132([1,2,3,4]))
print(find_132([3,1,4,2]))