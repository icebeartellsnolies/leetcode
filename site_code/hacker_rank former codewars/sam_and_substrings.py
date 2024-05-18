def substrings(n):
    subs=[]
    for i in range(len(n)):
        
        for j in range(i,len(n)):
            sub=n[i:j+1]
            subs.append(sub)
    sum=0
    for i in range(len(subs)):
        sum+=int(subs[i])
    return (sum%((10**9)+7))
print(substrings('972698438521'))