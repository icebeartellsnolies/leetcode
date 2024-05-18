# print(list(bin(3)))
def count_bits(n):
    answer=[]
    for i in range(n+1):
        lst=(list(bin(i)))
        lst.pop(0)
        lst.pop(0)

        count=0
        for b in lst:
            if b=='1':
                count+=1
        answer.append(count)
    return answer

print(count_bits(5))

