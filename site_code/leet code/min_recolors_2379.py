def minimumRecolors(blocks,k):
    req=0
    for i in range(k):
        if blocks[i]=='W':
            req+=1
    ans=req
    pt1=1
    pt2=k
    while pt2<len(blocks):
        if blocks[pt1-1]=='W':
          req-=1
        if blocks[pt2]=='W':
            req+=1
        ans=min(ans, req)
        pt1+=1
        pt2+=1
    
    return ans

print(minimumRecolors("WBWBBBW", 2))
print(minimumRecolors("WBBWWBBWBW",7))
