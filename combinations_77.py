from itertools import combinations
def combine(n, k):
    nums=[]
    for num in range(n):
        nums.append(num+1)
    combos=list(combinations(nums,k))
    final=[]
    for i in range(len(combos)):
        sub=[]
        for j in range(len(combos[i])):
            sub.append(combos[i][j])
        final.append(sub)
    return final

# def combine(n, k):
#     return [[*combo] for combo in combinations(range(1, n + 1), k)]
print(combine(4,2))