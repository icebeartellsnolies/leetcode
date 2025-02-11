def difference(s,t):
    longest=t
    shortest=s
    if len(s)>len(t):
        longest=s
        shortest=t
    length=len(shortest)
    i=0
    indices=[]
    while i<length:
        if shortest[i] in longest:
            for j in range(len(longest)):
                if longest[j]==shortest[i] and j not in indices:
                    indices.append(j)
                    break

        i+=1
    string=''
    for i in range(len(longest)):
        if i in indices:
            continue
        else:
            string+=longest[i]
    return string

print(difference('aa','a'))
