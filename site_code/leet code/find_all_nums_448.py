def disappeared_nums(nums):
    most = len(nums)
    least = 1
    nums = set(nums)
    ans = []
    for i in range(least,most+1):
        if i not in nums:
            ans.append(i)
    return ans

# print(disappeared_nums([4,3,2,7,8,2,3,1]))
print(disappeared_nums([1,1]))