def longest_ss(s):
    if s=='':
        return 0
    pointer1, pointer2 = 0, 1
    max_length = 1
    while pointer2 < len(s):
        substring = s[pointer1:pointer2+1]
        if len(substring) != len(list(set(substring))):
            pointer1 += 1
        else:
            max_length = max(max_length, len(substring))
        pointer2 += 1
    return max_length
# NOTE: not mine
# def lengthOfLongestSubstring(s) :
#     start=0
#     end=0
#     maxx=0
#     a=set()
#     while end<len(s):
#         while s[end] in a:
#             a.remove(s[start])
#             start+=1
        
#         a.add(s[end])
#         maxx=max((end-start+1),maxx)
#         end+=1
#     return maxx
# print(lengthOfLongestSubstring("pwwkew"))
# print(longest_ss("abcabcbb"))
# print(longest_ss('bbbbbb'))