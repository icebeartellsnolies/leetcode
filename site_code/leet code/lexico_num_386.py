def lexico_num(n):
    arr=[]
    for i in range(1,n+1):
        arr.append(str(i))
    arr.sort()
    output=[int(i) for i in arr]
    return output
print(lexico_num(2))
