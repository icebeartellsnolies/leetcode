from collections import defaultdict
def divideArray(nums):
    dictionary=defaultdict(int)
    for n in nums:
        dictionary[n]+=1
    count=0
    for p in dictionary.items():
        c=p[1]
        count+=c//2
    if count==len(nums)//2:
        return True
    return False

print(divideArray([3,2,3,2,2,2]))
print(divideArray([1,2,3,4]))