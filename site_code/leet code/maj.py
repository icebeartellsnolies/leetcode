def majority_elm(nums):
    n=len(nums)
    map={}
    for num in nums:
        if num not in map:
            map[num]= 1
        else:
            map[num]+=1

print(majority_elm([2,2,1,1,1,2,2]))