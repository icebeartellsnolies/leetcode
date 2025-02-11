def add(num):
    num_str=str(num)
    lst=[]
    for i in num_str:
        lst.append(int(i))
    if len(lst)>1:
        while len(lst)!=1:
            sum=0
            for i in lst:
                sum+=i
            lst=[]
            for i in range(len(str(sum))):
                lst.append(int(str(sum)[i]))
            if len(lst)==1:
                return sum
    else:
        return num
print(add(0))