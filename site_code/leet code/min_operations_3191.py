def minOperations(nums):
    p=0
    length=len(nums)
    count=0
    while p+2<length:
        if nums[p]==0:
            for i in range(p,p+3):
                nums[i]=nums[i]^1
            count+=1
        p+=1

    if nums[-2]==0 or nums[-1]==0:
        return -1
    return count

print(minOperations([0,1,1,1]))
print(minOperations([0,1,1,1,0,0]))