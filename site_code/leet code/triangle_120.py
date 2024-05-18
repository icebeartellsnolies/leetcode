def min_path_sum(triangle):
    index=0
    sum=0
    for i in range(len(triangle)):
        if i==0:
            to_add=triangle[i][index]
            sum+=to_add
        else:
            if triangle[i][index]>triangle[i][index+1]:
                index=index+1
            to_add=triangle[i][index]
            sum+=to_add
    return sum

# print(min_path_sum([[2],[3,4],[6,5,7],[4,1,8,3]]))
print(min_path_sum([[-10]]))