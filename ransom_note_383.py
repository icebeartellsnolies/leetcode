def can_construct(ransomNote, magazine):
    constructed=''
    indices=[]
    for i in range(len(ransomNote)):
        for j in range(len(magazine)):
            if ransomNote[i]==magazine[j] and j not in indices:
                constructed+=magazine[j]
                indices.append(j)
                break
    
    if constructed==ransomNote:
        return True
    else:
        return False
    
print(can_construct('bg',"efjbdfbdgfjhhaiigfhbaejahgfbbgbjagbddfgdiaigdadhcfcj"))