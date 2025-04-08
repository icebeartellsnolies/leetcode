def numberOfAlternatingGroups(colors,k):
    length=len(colors)
    l=0
    r=1
    ans=0
    while r<length+k-1:
        if colors[(r-1)%length]!=colors[r%length]:
            if (r-l)+1==k:
                ans+=1
                l+=1
            
        else:
            l=r
        r+=1
    return ans

# print(numberOfAlternatingGroups([0,1,0,1,0],  3))
print(numberOfAlternatingGroups([1,1,0,1],  4))
    