from itertools import combinations

def subsets(nums):
    comb=[]
    for i in range(len(nums)+1):
        combos=list(combinations(nums,i))
        for com in combos:
            comb.append(list(com))
    return comb

print(subsets([1,2,3]))
# gemini list comprehension way for the code

# def subsets(nums):
#     return [list(combo) for i in range(len(nums) + 1) for combo in combinations(nums, i)]

# print(subsets([1, 2, 3]))
