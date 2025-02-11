def missing_pos(lst):
    only_pos=[]
    for i in range(len(lst)):
        if lst[i] >= 1:
            only_pos.append(lst[i])
    if len(only_pos)==0:
        return 1
    only_pos.sort()
    
    last_val=only_pos[-1]
    for i in range(1,(last_val+2)):
        if i not in only_pos:
            missing_int=i
            break
    return missing_int

# # GEMINI CODE
def missing_pos(lst):

    n = len(lst)
    # Handle the edge case where no positive integers are present
    if n == 0 or all(x <= 0 for x in lst):
        return 1
    lst.sort()
    # Use the list itself as constant space for marking visited elements
    for i in range(n):
        # Validate indices to avoid out-of-bounds errors
        if 0 <= lst[i] - 1 < n and lst[i] - 1 != i and lst[i] > 0:
            # Swap the element with the value it should point to (if valid)
            temp = lst[i]
            lst[i], lst[temp - 1] = lst[temp - 1], lst[i]

    # Find the first element that doesn't point to its index (i.e., the missing integer)
    for i in range(n):
        if lst[i] != i + 1:
            return i + 1

    # If all elements are correctly positioned (no missing positive integers),
    # return the element that should follow the last element (n + 1)
    return n + 1

print(missing_pos([3,4,-1,1]))

# AMIR'S CODE

def firstMissingPositive(nums) -> int:
    m = 1
    a = 0
    nums = set(nums)
    for i in range(len(nums)):
        if m in nums:
            m = m + 1
        else:
            a = a + 1
            return m
    if a == 0:
        return max(nums) + 1

print(firstMissingPositive([3,4,-1,1]))