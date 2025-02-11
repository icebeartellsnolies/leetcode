# def longestCommonSubsequence(text1, text2):
#     commons=[]
#     if len(text1)<len(text2):
#         shortest_txt=text1
#         longest_txt=text2
#     else:
#         shortest_txt=text2
#         longest_txt=text1
#     common_str=''
#     indices=[]
#     for letter in range(len(shortest_txt)):
#         if shortest_txt[letter] in text2:
#             for common_ltr in range(len(longest_txt)):
#                 if shortest_txt[letter]==longest_txt[common_ltr]:
#                     if common_ltr not in indices:
#                         if len(indices)==0:
#                             indices.append(common_ltr)
#                             common_str+=shortest_txt[letter]
#                             commons.append(common_str)
#                             break
#                         else:
#                             if common_ltr > indices[-1]:
#                                 indices.append(common_ltr)
#                                 indices.sort()
#                                 common_str+=shortest_txt[letter]
#                                 commons.append(common_str)
#                                 break
#     if len(commons)>0:
#         longest=len(commons[0])
#         for i in range(len(commons)):
#             if len(commons[i])>(longest):
#                 longest=len(commons[i])
    
#         return longest
#     else:
#         return 0
# print(longestCommonSubsequence("oxcpqrsvwf","shmtulqrypy"))

def longestCommonSubsequence(text1, text2):
    dp=[[0 for j in range(len(text2)+1)] for i in range(len(text1)+1)]
    for i in range(len(text1)-1,-1,-1):
        for j in range(len(text2)-1,-1,-1):
            if text2[j]==text1[i]:
                dp[i][j]=1+dp[i+1][j+1]
            else:
                dp[i][j]=max(dp[i][j+1],dp[i+1][j])
    return dp[0][0]
print(longestCommonSubsequence("oxcpqrsvwf","shmtulqrypy"))