def majority_elm(nums):
    n=len(nums)
    map={}
    for num in nums:
        if num not in map:
            map[num]= 1
        else:
            map[num]+=1

    for num in nums:
        count=map.get(num)
        if count>n/2:
            return num

print(majority_elm([2,2,1,1,1,2,2]))