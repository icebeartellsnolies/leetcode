def two_sum(numbers, target):
    pointer1 = 0
    pointer2 = len(numbers)-1
    while pointer1 < pointer2:
        altogether = numbers[pointer1] + numbers[pointer2]
        if altogether == target:
            return [pointer1+1, pointer2+1]
        elif altogether < target:
            pointer1 += 1
        else:
            pointer2 -= 1
    
print(two_sum([2,7,11,15], 9))