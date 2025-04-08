import itertools
def getPermutation(n, k):
    permutations=[]
    nums=[]
    for num in range(n):
        nums.append(num+1)
    for permutation in itertools.permutations(nums):
        permutations.append(permutation)
    string=''
    for i in range(len(permutations[k-1])):
        string+=str(permutations[k-1][i])
    return string

print(getPermutation(3,3))