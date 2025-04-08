from collections import defaultdict
def minimumIndex(nums):
    hash_map=defaultdict(int)
    length=len(nums)
    for num in nums:
        hash_map[num]+=1

    dom_element=freq=None
    for entry in hash_map.items():
        if entry[1]>length//2:
            dom_element=entry[0]
            freq=entry[1]
            break
    
    f1=0
    f2=0
    for n in range(length):
        if nums[n]==dom_element:
            f1+=1
            f2=freq-f1
            l1=n+1
            l2=length-l1
            if f1>l1//2 and f2>l2//2:
                return n
    return -1

print(minimumIndex(nums = [3,3,3,3,7,2,2]))