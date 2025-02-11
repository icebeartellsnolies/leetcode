def countKConstraintSubstrings(s,k):
    valid=0
    for l in range(len(s)):
        r=l
        while r<len(s):
            ones = s[l:r+1].count('1')
            zeroes = s[l:r+1].count('0')
            if ones<=k or zeroes<=k:
                valid+=1
            r+=1
    return valid

# print(countKConstraintSubstrings("10101",1))
print(countKConstraintSubstrings("1010101",2))