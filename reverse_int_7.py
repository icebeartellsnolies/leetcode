def reverse(x):

    reverse=''
    string=str(x)
    if string[0]=='-':
        reverse='-'
        for i in range((len(string)-1),0,-1):
            reverse=reverse+string[i]
    else:
        reverse=reverse+(string[::-1])
    reverse=int(reverse)
    if reverse<-2**31 or reverse> 2**31 - 1:
        return 0
    else:
        return reverse
print(reverse(-987))