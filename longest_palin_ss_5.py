def longestPalindrome(s):
    if len(s)<2:
        return s
    palindromes=[]
    for pointer1 in range(len(s)):
        for pointer2 in range(len(s)-1,-1,-1):
            sequence=s[pointer1:pointer2+1]
            rev_seq=sequence[::-1]
            if sequence==rev_seq:
                palindromes.append(sequence)
    longest=palindromes[0]
    for palin in range(len(palindromes)):
        if len(palindromes[palin])>len(longest):
            longest=palindromes[palin]
    return longest
print(longestPalindrome("cbbd"))

# BLACK BOX CODE:
# def longestPalindrome(s):
#     if len(s) < 2:
#         return s

#     n = len(s)
#     dp = [[False] * n for _ in range(n)]
#     longest = ""

#     # All substrings of length 1 are palindromes
#     for i in range(n):
#         dp[i][i] = True
#         longest = s[i]

#     # Check for sub-string of length 2
#     for i in range(n - 1):
#         if s[i] == s[i + 1]:
#             dp[i][i + 1] = True
#             longest = s[i:i + 2]

#     # Check for lengths greater than 2 using bottom-up DP approach
#     for length in range(3, n + 1):
#         for i in range(n - length + 1):
#             j = i + length - 1
#             if s[i] == s[j] and dp[i + 1][j - 1]:
#                 dp[i][j] = True 
#                 if length > len(longest):
#                     longest = s[i:j + 1]

#     return longest
# print(longestPalindrome("babad"))