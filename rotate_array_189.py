# def rotate(nums,k):
#     for change in range(k):
#         popped=nums.pop(-1)
#         nums.insert(0,popped)
#     return nums

def rotate(nums,k):
    end_point = len(nums) - k
    second = []
    first = []
    for i in range(len(nums)):
        if i < end_point:
            first.append(nums[i])
        else:
            second.append(nums[i])
    nums = second + first
    return nums
# print(rotate([-1,-100,3,99],2))
print(rotate([1,2,3,4,5,6,7],3))