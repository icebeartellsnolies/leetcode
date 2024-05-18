def make_beautiful(matrix):
    target=matrix[2][2]
    one_index=[None,None]
    for i in range(5):
        for j in range(5):
            if matrix[i][j]==1:
                one_index[0]=i
                one_index[1]=j
    
    row_difference=2-int(one_index[0])
    column_difference=2-int(one_index[1])

    # row movement
    count=0
    while row_difference!=0:
        
        if row_difference<0:
            changed_row= int(one_index[0])-1
            one_index[0]=(changed_row)
            count=count+1
        row_difference=2-int(one_index[0])
        if row_difference>0:
            changed_row=int(one_index[0])+1
            one_index[0]=(changed_row)
            count=count+1
        row_difference=2-int(one_index[0])

    #   column movement
            
    while column_difference!=0:
        
        if column_difference<0:
            changed_col= int(one_index[1])-1
            one_index[1]=(changed_col)
            count=count+1
        column_difference=2-int(one_index[1])
        if column_difference>0:
            changed_col=int(one_index[1])+1
            one_index[1]=(changed_col)
            count=count+1
        column_difference=2-int(one_index[1])
    
    return count
mat=[[0,0,0,0,0],[0,0,0,0,1],[0,0,0,0,0],[0,0,0,0,0],[0,0,0,0,0]]
print(make_beautiful(mat))