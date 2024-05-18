def challenge(grid):
    sorted_grid=[]
    for i in grid:
        i=list(i)
        i.sort()
        sorted_grid.append(i)
    for sub_grid in range(len(sorted_grid)-1):
        for letter in range(len(grid[sub_grid])):
            if sorted_grid[sub_grid][letter]>sorted_grid[sub_grid+1][letter]:
                return 'NO'
    return 'YES'

print(challenge(['ebacd', 'fghij', 'olmkn', 'trpqs', 'xywuv']))