def wrong_subtraction(number,decrement_times):
    
    lst_number=[]
    for i in range(len(str(number))):
        to_append=(str(number)[i])
        lst_number.append(int(to_append))
    start=1
    while start<=decrement_times:
        if lst_number[-1]!=0:
            lst_number[-1]=(int(lst_number[-1])-1)
        else:
            lst_number.pop(-1)
        start+=1
    string=''
    for i in range(len(lst_number)):

        string+=str(lst_number[i])
    string=int(string)
    return string
x,y=map(int,input().split())
print(wrong_subtraction(x,y))