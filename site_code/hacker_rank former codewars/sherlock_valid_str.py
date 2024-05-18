from collections import Counter
def is_valid(s):
    unique_s=list(set(s))
    counts=[]
    for i in unique_s:
        counts.append(s.count(i))
    unique_count=list(set(counts))
    if len(unique_count)==1:
        return 'YES'
    elif len(unique_count)==2:
    # NOTE: WRONG ON 2 TEST CASES
    #     c1=counts.count(unique_count[0])
    #     c2=counts.count(unique_count[1]) 
    #     if c1==1 or c2==1:
    #         return 'YES'
    # return 'NO'
    # NOTE: WRONG ON 2 TEST CASES; 7&13
        counts.sort()
        if abs(counts[0]-counts[-1])==1:
            if counts[-2]!=counts[-1] or counts[0]!=counts[1]:
                return 'YES'
    return 'NO'

# print(is_valid('aaaabbcc'))
print(is_valid('abcdefghhgfedecba'))
# print(is_valid('aabbcd'))
# print(is_valid('aabbc'))

# SOMEONE FROM DISCUSSIONS
def isValid(s):
    freq=Counter(s)
    freq = list(freq.values())

    if max(freq) == min(freq):
        return "YES"  # all same freq
    elif len(set(freq)) > 2:
        return "NO"  # more than one freq
    elif freq.count(max(freq)) > 1 and freq.count(min(freq)) > 1:
        return "NO"  # two freqs of more than 2 elems
    elif min(freq) == 1 and freq.count(min(freq)) == 1:
        return "YES"  # can pop the only freq of one
    elif max(freq) - min(freq) == 1 and freq.count(max(freq)) == 1:
        return "YES"  # can reduce the higher by one
    else:
        return "NO"