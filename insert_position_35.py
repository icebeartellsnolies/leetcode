def search_insert(nums, target):
    if target in nums:
        for i in range(len(nums)):
            if nums[i]==target:
                index=i
                break
    else:
        nums.append(target)
        nums.sort()
        for i in range(len(nums)):
            if target==nums[i]:
                index=i
                break
    return index
print(search_insert([1,3,5,6],2))