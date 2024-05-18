def move(nums):
    zeroes=[]
    for i in range(len(nums)):
        if 0 in nums:
            nums.remove(0)
            zeroes.append(0)
        else:
            break
    nums=nums+zeroes
    return nums
print(move([0,1,0,3,12]))

# def move(nums):
#     for i in range(len(nums)):
#         for j in range(i,len(nums)):
#             if nums[]
    