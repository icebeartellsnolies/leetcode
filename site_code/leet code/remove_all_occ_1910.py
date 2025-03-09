def removeOccurrences(s, part):
    new_s=""
    for i in range(len(s)-2-len(part)+1):
        if s[i]==part[0] and s[i:len(part)]==part:
            
            continue
        else:
            new_s+=s[i]
    return new_s

print(removeOccurrences("daabcbaabcbc","abc"))
                