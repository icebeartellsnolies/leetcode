from itertools import permutations
def largest(nums):
    comb=list(permutations(nums,len(nums)))
    greatest_num = 0
    for c in comb:
        num = ''.join(str(i) for i in c)
        num=int(num)
        if num > greatest_num:
            greatest_num = num
    return str(greatest_num)

print(largest([3,30,34,5,9]))
print(largest([10,2]))