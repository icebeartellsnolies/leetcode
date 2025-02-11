def search_matrix(matrix, target):
    to_return=False
    for row in range(len(matrix)):
        for col in range(len(matrix[row])):
            if matrix[row][col]==target:
                to_return=True
                return to_return
    return to_return

print(search_matrix([[1,3,5,7],[10,11,16,20],[23,30,34,60]],13))