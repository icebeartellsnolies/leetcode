def largestDivisibleSubset(nums):
    length=len(nums)
    dp=[1]*length
    nums.sort()
    for i in range(1,length):
        for j in range(0,i):
            if nums[i]%nums[j]==0 and (1+dp[j]>dp[i]):
                dp[i]+=1
    
    max_index=0
    max_e=float('-inf')
    for i in range(length):
        if dp[i]>=max_e:
            max_e=dp[i]
            max_index=i

    prev=-1
    ans=[]
    for i in range(max_index,-1,-1):
        if dp[i]==max_e and (prev%nums[i]==0 or prev==-1):
            prev=nums[i]
            ans.append(prev)
            max_e-=1
    
    return ans

print(largestDivisibleSubset([1,2,3]))
print(largestDivisibleSubset([1, 2, 4, 8]))
print(largestDivisibleSubset([4,8,10,240]))