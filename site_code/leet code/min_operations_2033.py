def minOperations(grid,x):
    flattened=[]
    remainder=grid[0][0]%x
    for i in range(len(grid)):
        for j in range(len(grid[i])):
            if grid[i][j]%x==remainder:
                flattened.append(grid[i][j])
            else:
                return -1
    
    flattened.sort()
    mid=flattened[len(flattened)//2]
    steps=0
    for i in range(len(flattened)):
        s=abs(flattened[i]-mid)//x
        steps+=s
    return steps

print(minOperations([[1,2],[3,4]], x = 2))