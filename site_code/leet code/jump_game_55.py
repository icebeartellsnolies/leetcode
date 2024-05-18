def can_jump(nums):
    length=len(nums)
    if length>1:
        to_return=False
        i=length-1
        j=i-1
        while j>=0:
            diff=i-j
            if nums[i]>=diff:
                pointer=j
                i-=1
                if pointer==0:
                    to_return=True
                    break
            j-=1
    else:
        to_return=True
    return to_return

print(can_jump([3,2,1,0,4]))
        
        