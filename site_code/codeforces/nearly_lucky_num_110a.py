def is_lucky(number):
    number=str(number)
    count_4=0
    count_7=0
    for num in range(len(number)):
        if int(number[num])==4:
            count_4+=1
        if int(number[num])==7:
            count_7+=1

    if  count_4+count_7==4 or count_4+count_7==7:
        print('YES')
    else:
        print('NO')

x=int(input())
is_lucky(x)