def countServers(grid):

    row_count=[]
    for i in range(len(grid)):
        count=0
        for j in range(len(grid[i])):
            if(grid[i][j]==1):
                count+=1
        row_count.append(count)
    
    col_count=[]
    for i in range(len(grid[0])):
        count=0
        for j in range(len(grid)):
            if(grid[j][i]==1):
                count+=1
        col_count.append(count)

    total=0
    for i in range(len(grid)):
        for j in range(len(grid[i])):
            if(grid[i][j]==1):
                if(row_count[i]>1 or col_count[j]>1):
                    total+=1
    return total

print(countServers([[1,0,0,1,0],[0,0,0,0,0],[0,0,0,1,0]]))