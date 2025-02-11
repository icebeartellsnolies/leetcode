def my_atoi(s):
    s=s.lstrip()
    resultant=''
    alphabets=''
    for i in range(len(s)):
        if i==0 and (s[i]=='-' or s[i]=='+' ):
            resultant+=s[i]
        elif ord(s[i])>=48 and ord(s[i])<=57 and len(alphabets)==0:
            resultant+=s[i]
        else :
            alphabets+=s[i]
    #final is created if resultant=='-' or resultant=='+'
    final=''
    if len(resultant)<2:
        for i in range(len(resultant)):
            if ord(s[i])>=48 and ord(s[i])<=57:
                final+=resultant[i]
    else:
        final=resultant
    if len(final)==0:
        return 0

    final=int(final)
    if final<-2**31 or final> 2**31 - 1:
        if final> 2**31 - 1:
            return (2**31)-1
        if final<-2**31:
            return -2**31
    return final
print(my_atoi("2147483647"))