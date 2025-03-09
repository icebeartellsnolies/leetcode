def findMissingAndRepeatedValues(grid):
    st=set()
    flattened=[None]*(len(grid)*len(grid))
    ans=[None]*2

    for i in range(len(grid)):
        for j in range(len(grid[i])):
            num=grid[i][j]
            if num in st:
                ans[0]=grid[i][j]
            else:
                st.add(num)
            flattened[num-1]=num
    
    for i in range(len(flattened)):
        if flattened[i]==None:
            ans[1]=i+1
    return ans

print(findMissingAndRepeatedValues([[1,3],[2,2]]))
 