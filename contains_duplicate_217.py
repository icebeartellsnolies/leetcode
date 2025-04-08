def contains_dup(nums):
    if len(nums)>1:
        for i in range(len(nums)):
            for j in range(len(nums)):
                if i!=j:
                    if nums[i]==nums[j]:
                        return True

    return False

print(contains_dup([1,5,-2,-4,0]))