from itertools import combinations
def subsetXORSum(nums):
    power_subset=[]
    for i in range(1,len(nums)+1):
        combs=list(combinations(nums,r=i))
        power_subset.extend(combs)
    sum=0 
    for c in power_subset:
        s=0
        for j in range(len(c)):
            s=s^c[j]      
        sum+=s
    return sum

print(subsetXORSum([5,1,6]))
print(subsetXORSum([1,3]))

