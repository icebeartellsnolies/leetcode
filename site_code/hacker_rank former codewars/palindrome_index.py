def palindromeIndex(s):
    # Write your code here
    if s==s[::-1]:
        return -1
    for i in range(len(s)):
        copy_s=list(s)
        copy_s.pop(i)
        if copy_s==copy_s[::-1]:
            return i
    return -1
print(palindromeIndex('baa'))