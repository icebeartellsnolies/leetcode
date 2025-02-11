def two_sum(nums,target):
    sum=0
    for i in range(len(nums)):
        for j in range((len(nums)-1),0,-1):
            sum=nums[i]+nums[j]
            if sum==target and i!=j:
                index1=i
                index2=j
                break
    ans=[]
    if index1<index2:
        ans=[index1,index2]
    else:
        ans=[index2,index1]
    return ans
arr=[3,2,4]
target=6
print(two_sum(arr,target))