from collections import Counter
def remove_dup_letters(s):
    count=Counter(s)
    ans=""
    for i in range(len(s)):
        if count[s[i]]>1:
            count[s[i]]-=1
        else:
            ans+=s[i]
    return ans

# print(remove_dup_letters("bcabc"))
print(remove_dup_letters("cbacdcbc"))