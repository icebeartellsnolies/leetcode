# def sort_colors(nums):
#     nums.sort()
#     return nums


def sort_colors(nums):
    for i in range(len(nums)):
        for j in range(i,len(nums)):
            if nums[i]>nums[j]:
                nums[i],nums[j]=nums[j],nums[i]
    return nums
print(sort_colors([2,0,2,1,1,0]))