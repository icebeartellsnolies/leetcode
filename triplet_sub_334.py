def increasing_triplet(nums):

    for i in range((len(nums))-2):
        for j in range((len(nums))-1):
            for k in range(len(nums)):
                if i<j and j<k:
                    if nums[i]<nums[j] and nums[j]<nums[k]:
                        return True
    return False

print(increasing_triplet([20,100,10,12,5,13]))
