def del_duplicates(s):
    l=len(s)
    new_word=[]
    for r in range(l):
        new_word.append(s[r])
    length=len(new_word)
    j=0
    while j <length:
        i=0
        while i<(length):
            if new_word[i]==new_word[j] and i!=j:
                new_word.pop(i)
            i=i+1
            length=len(new_word)
        length=len(new_word)
        j=j+1
    final=''
    for r in range(len(new_word)):
        final=final+new_word[r]
    return final
print(del_duplicates('mlmemamrmckm'))