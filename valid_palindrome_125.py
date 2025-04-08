def isPalindrome(s):
    string=''
    for i in range(len(s)):
        if ord(s[i])>=97 and ord(s[i])<=122 or ord(s[i])>=65 and ord(s[i])<=90 or ord(s[i])>=48 and ord(s[i])<=57:
            if ord(s[i])>=65 and ord(s[i])<=90:
                new_char=chr(ord(s[i])+32)
                string+=new_char
            else:
                string+=s[i]
    
    rev_string=string[::-1]
    if rev_string==string:
        return True
    else:
        return False

print(isPalindrome("0P"))