count_of_nums=int(input())
lst=[]
for nums in range(count_of_nums):
    lst.append(list(map(int,input().split())))

numerator=1
denominator=1
for nums in range(count_of_nums):
    for num in range(len(lst[nums])):
        if num==0:
            numerator*=lst[nums][num]
        else:
            denominator*=lst[nums][num]

minimum=min(numerator,denominator)
simplifier=1
for num in range(2,minimum):
    if numerator%num==0 and denominator%num==0 and num>simplifier:
        simplifier=num
print(int(numerator/simplifier),int(denominator/simplifier))