from collections import Counter
def is_permutation(s1, s2):
    pointer1 = 0
    pointer2 = len(s1) - 1
    s1_count = Counter(s1)
    while pointer2 < len(s2):
        substring = s2[pointer1:pointer2+1]
        if s1_count == Counter(substring):
            return True
        pointer1 += 1
        pointer2 += 1
    return False

print(is_permutation("ab","eidbaooo"))
print(is_permutation("ab","eidbaooo"))