def check(nums):
    length = len(nums)
    size=1
    if length==1:
        return True
    for i in range(1, 2*length):
        if(nums[i%length]>=nums[(i-1)%length]):
            size+=1
            if size==length:
                return True
        else:
            size=1
    return False


print(check([3,4,5,1,2]))
[1,2,3,4,5]