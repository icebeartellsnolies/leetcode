def longest_ss(s,k):
    mapping = {}
    l = 0
    r = 0
    min_val = float('inf')
    max_length = 0
    while r < len(s) and l < len(s):
        if s[r] in mapping:
            mapping[s[r]] += 1
        else:
            mapping[s[r]] = 1
        min_val = min(mapping.values())
        length = r-l + 1
        if min_val >= k:
            max_length = max(max_length, length)
        if s[r+1] in mapping:
            r += 1
        else:
            l += 1 
    return max_length

# print(longest_ss('aaabb',3))
print(longest_ss('ababbc',2))
