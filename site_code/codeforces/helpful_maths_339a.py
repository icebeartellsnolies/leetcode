def helpful(to_calculate):
    only_numbers=[]
    for i in to_calculate:
        if ord(i)>=48 and ord(i)<=57:
            only_numbers.append(i)

    for i in range(len(only_numbers)):
        for j in range(len(only_numbers)):
            if only_numbers[i]<only_numbers[j]:
                only_numbers[i],only_numbers[j]=only_numbers[j],only_numbers[i]
    
    to_sum=''
    for i in range(len(only_numbers)):
        if i!=len(only_numbers)-1:
            to_sum=to_sum+only_numbers[i]+'+'
        else:
            to_sum=to_sum+only_numbers[i]
    return to_sum
x=input()
print(helpful(x))