def find_diagonal_order(mat):
    rows = len(mat)
    cols = len(mat[0])
    # first = mat[0][0]
    # last = mat[rows-1][cols-1]
    diagonals_order = []

    diagonal_start_locs = []
    # put first row in diagonal_start_locs
    for i in range(cols):
        loc = (0,i)
        diagonal_start_locs.append(loc)
    # put last entry of every row in in diagonal_start_locs
    for i in range(1,rows):
        loc = (i,cols-1)
        diagonal_start_locs.append(loc)
    for elem in range(len(diagonal_start_locs)):
        
        loc = diagonal_start_locs[elem]
        # r = loc[0]
        # c = loc[1]
        row,col = loc
        # diagonals_order.append(mat[row][col])
        to_reverse = False
        if elem%2 == 0:
            to_reverse = True
        values = []
        while row < rows and col >= 0:
            val = mat[row][col]
            row += 1
            col -= 1
            values.append(val)
        if not to_reverse:
            diagonals_order.extend(values)
        else:
            values = values[::-1]
            diagonals_order.extend(values)
    return diagonals_order
mat = [[1,2,3],[4,5,6],[7,8,9]]
print(find_diagonal_order(mat))