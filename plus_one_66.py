def addition(to_solve):
    string=''
    for i in range(len(to_solve)):
        string+=str(to_solve[i])
    num=int(string)
    num=num+1
    result_list = [int(digit) for digit in str(num)]
    return result_list
print(addition([9]))