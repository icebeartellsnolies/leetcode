def repeated_ss(s):
    i=0
    ss = ''
    while i<len(s)-1:
        ratio = len(s)//(i+1)
        ss+=s[i]
        recreated_ss = (ss)*ratio
        if recreated_ss == s:
            return True
        i+=1
    return False

# print(repeated_ss("abab"))
print(repeated_ss("abcabcabcabc"))