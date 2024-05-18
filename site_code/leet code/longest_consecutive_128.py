def longest_consecutive(nums):
    if len(nums) == 0:
        return 0
    nums = list(set(nums))
    nums.sort()
    pointer1 = 0
    pointer2 = 1
    count = 1
    counts = []
    while pointer2 < len(nums):
        if ((nums[pointer2-1] + 1) != nums[pointer2]):
            if pointer2-pointer1 == 1:
                pointer1 += 1
                pointer2 += 1
                counts.append(count)
                count = 1
            else:
                if pointer2+1 < len(nums):
                    pointer1 = pointer2
                    pointer2 += 1
                    counts.append(count)
                    count = 1
                else:
                    counts.append(count)
                    return max(counts)
        else:
            pointer2 += 1
            count += 1
    counts.append(count)
    return max(counts)

print(longest_consecutive([0,3,7,2,5,8,4,6,0,1]))
print(longest_consecutive([100,4,200,1,3,2]))
print(longest_consecutive([1,2,0,1]))
print(longest_consecutive([9,1,4,7,3,-1,0,5,8,-1,6]))
print(longest_consecutive([9,1,-3,2,4,8,3,-1,6,-2,-4,7]))
print(longest_consecutive([4,0,-4,-2,2,5,2,0,-8,-8,-8,-8,-1,7,4,5,5,-4,6,6,-3]))