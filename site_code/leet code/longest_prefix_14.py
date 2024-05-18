def longest(strs):
    shortest=strs[0]
    for word in range(len(strs)):
        if len(strs[word])<len(shortest):
            shortest=strs[word]
    common=''

    for i in range(len(shortest)):
        trues=[]
        for j in range(0,len(strs)):
            if shortest[i]==strs[j][i]:
                if (shortest!=strs[j]):
                    trues.append(True)
            else:
                trues.append(False)
        
        if False not in trues:
            common=common+shortest[i]
        if False in trues:
            break
    
    return common

print(longest(["reflower","flow","flight"]))
