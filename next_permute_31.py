import copy
def next_permutation(nums):
    if len(nums) < 2:
        return nums
    l = len(nums) - 2
    r = len(nums) - 1
    cop = copy.deepcopy(nums)  
    cop.sort(key=lambda x:-x)
    if nums == cop:
        nums.sort()
        return nums
    while l >= 0:
        if nums[l] < nums[r]:
            nums[l], nums[r] = nums[r], nums[l]
            return nums
        elif l > 0 and nums[l-1] < nums[r]:
            nums[l-1], nums[r] = nums[r], nums[l-1]
            first = nums[:l]
            second = nums[l:]
            second.sort()
            nums = first+second
            return nums
        l -= 1
        r -= 1

# print(next_permutation([1,2,3]))
# print(next_permutation([3,2,1]))
# print(next_permutation([1,2]))
print(next_permutation([1,3,2]))