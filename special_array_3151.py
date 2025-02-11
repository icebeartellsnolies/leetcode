def isArraySpecial(nums):
    for r in range(1,len(nums)):
        l=r-1
        odd1=odd2=False
        if nums[r]%2!=0:
            odd1=True
        if nums[l]%2!=0:
            odd2=True
        if odd1==odd2:
            return False
    return True

# print(isArraySpecial([2,1,4]))
# print(isArraySpecial([1]))
print(isArraySpecial([4,3,1,6]))