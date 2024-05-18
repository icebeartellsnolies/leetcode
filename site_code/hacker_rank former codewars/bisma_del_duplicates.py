string='aaaaaaaabbbbbbbbbaaabababaaaaaababaabn'
string1=''
length=len(string)
string1=string1+string[0]
for c in range(1,length):
    value=True
    for r in range(c):
        if string[c]!=string[r]:
            value=True
        else:
            value=False
            break
    if value==True:
        string1=string1+string[c]
print(string1)