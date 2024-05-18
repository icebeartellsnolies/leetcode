def no_repetition(total,combination):
    to_drop=0
    for i in range(total-1):
        j=i+1
        if combination[i]==combination[j]:
            to_drop+=1
    return to_drop
x=int(input())
y=input()
print(no_repetition(x,y))