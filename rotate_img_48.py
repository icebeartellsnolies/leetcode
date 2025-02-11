def rotate_90(matrix):
    parent=[]
    for i in range(len(matrix)):
        subs=[]
        for j in range(len(matrix)-1,-1,-1):
            subs.append(matrix[j][i])
        parent.append(subs)
    return parent

print(rotate_90([[1,2,3],[4,5,6],[7,8,9]]))