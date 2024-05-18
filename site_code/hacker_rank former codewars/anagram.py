from collections import Counter
def anagram(s):
    if len(s)%2 != 0:
        return -1
    mid=(len(s)//2)
    half1=s[:mid]
    half2=s[mid:]
    c1=Counter(half1)
    c2=Counter(half2)
    ans=((c2-c1).total())
    return ans
print(anagram('asdfjoieufoa'))
print(anagram('abcd'))