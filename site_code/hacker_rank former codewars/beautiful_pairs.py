def beautiful_pairs(A, B):
    counter=0
    indices_done=[]
    for i in range(len(A)):
        for j in range(len(B)):
            if A[i]==B[j] and j not in indices_done:
                counter+=1
                indices_done.append(j)
                break
    length=len(indices_done)

    if len(indices_done)<len(A) and len(indices_done)<len(B):
        length+=1
    else:
        length-=1
    return length


print(beautiful_pairs([1],[1]))