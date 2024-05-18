def rearrange(total,position):
    resultant=[]
    for i in range(1,total+1):
        if i%2!=0:
            resultant.append(i)
    for i in range(1,total+1):
        if i%2==0:
            resultant.append(i)
    return resultant[position-1]
    
print(rearrange(7,7))