# # NOTE: my solution
# from collections import Counter
# def is_valid(string,k):
#     count = Counter(string)
#     altogether = count.total()
#     if len(count) <= k+1:
#         count = list(sorted(count.items(), key=lambda x:x[1]))
#         to_subtract = count[-1][1]
#         if altogether - to_subtract <= k:
#             return True
#     return False
# def replaced(s,k):
#     pointer1 = 0
#     pointer2 = 1
#     max_length = 1
#     while pointer2 < len(s):
#         substring = s[pointer1:pointer2+1] 
#         validity = is_valid(substring,k)
#         if validity:
#             pointer2 += 1
#             max_length = max(max_length, len(substring))
#         else:
#             pointer1 += 1
        
#     return max_length
# NOTE: neetcode's
def replaced(s,k):
    count = {}
    res = 0
    l=0
    for r in range(len(s)):
        count[s[r]] = 1 + count.get(s[r], 0) 
        if (r-l+1) - max(count.values()) > k:  # r-l+1 gives the length of substring we are considering
            count[s[l]] -= 1
            l += 1
        res = max(res, r-l+1)
    return res
print(replaced("AABABBA",1))
print(replaced('ABAB',2))
print(replaced("ABCDE",1))