import copy
def maxSubArray(nums):
    length=len(nums)
    if length!=1:
        sums=[]
        for i in range(length):
            for j in range(length,-1,-1):
                sub=nums[i:j]
                sum=0
                to_append=False
                for k in range(len(sub)):
                    sum+=sub[k]
                    to_append=True
                if to_append==True:
                    sums.append(sum)
    else:
        sums=copy.deepcopy(nums)
    return max(sums)
print(maxSubArray([-2,-1]))