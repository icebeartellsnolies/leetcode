def search(nums, target):
    if target not in nums or len(nums)==0:
        return -1
    low=0
    high=len(nums)-1
    while low<=high:
        mid=(low+high)//2
        if nums[mid]==target:
            if mid>0 and nums[mid-1]==target:
                high = mid -1
            else:
                return mid
        elif nums[mid] > target:
            high = mid - 1
        elif nums[mid] < target:
            low = mid + 1

print(search([5],5))