def search(nums, target):
    index=-1
    for num in range(len(nums)):
        if nums[num]==target:
            index=num
            break
    return index
print(search([4,5,6,7,0,1,2],0))