def moveZeroes(nums):
    no_of_zeroes=nums.count(0)
    for i in range(no_of_zeroes):
        for pt1 in range(len(nums)-1):
            pt2=pt1+1
            if (nums[pt1]==0 and nums[pt2]!=0):
                nums[pt1],nums[pt2]=nums[pt2],nums[pt1]
    return nums

def moveZeroes( nums):
    nonzero, i = 0, 0  # Initialize pointers
    n = len(nums)
    while i < n:
        if nums[i] != 0:
            # Swap non-zero element with the element at the `nonzero` pointer
            nums[i], nums[nonzero] = nums[nonzero], nums[i]
            nonzero += 1  # Move `nonzero` pointer
        i += 1  # Move `i` pointer
    return nums
print(moveZeroes([0,1,0,3,12]))