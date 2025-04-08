from collections import defaultdict
def numberOfSubstrings(s):
    hash_map=defaultdict(int)
    count=0
    left=0
    for r in range(len(s)):
        hash_map[s[r]]+=1
        while hash_map['a']>=1 and hash_map['b']>=1 and hash_map['c']>=1:
            count+=len(s)-r
            hash_map[s[left]]-=1
            left+=1
    return count

print(numberOfSubstrings('abcabc')) 
