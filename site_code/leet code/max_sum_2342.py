def maximumSum(nums):
    groups={}
    for i in range(len(nums)):
        sum=0
        org=num=nums[i]
        while num>0:
            n=num%10
            num=num//10
            sum+=n
        if sum not in groups:
            groups[sum]=[]
        groups[sum].append(org)
    
    sum=-1
    for elems in groups.values():
        elems=sorted(elems)
        if len(elems)>1:
            one=elems[-1]
            two=elems[-2]
            sum=max(one+two,sum)
    return sum

print(maximumSum([18,43,36,13,7]))
print(maximumSum([10,12,19,14]))
