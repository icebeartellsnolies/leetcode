# def remove_elem(nums,val):
#     nums.sort()
#     l = 0
#     r = len(nums)-1
#     for l in range(len(nums)):
#         if nums[l] == val:
#             nums[l], nums[r] = nums[r], nums[l]
#             r -= 1
            
#             if r - l == 1:
#                 break
    
#     return r

# NOTE:CHATGPT
def remove_elem(nums, val):
    l = 0
    r = len(nums) - 1

    while l <= r:
        if nums[l] == val:
            nums[l], nums[r] = nums[r], nums[l]
            r -= 1
        else:
            l += 1
    
    return l

print(remove_elem([0,1,2,2,3,0,4,2],2))
print(remove_elem([3,2,2,3],3))