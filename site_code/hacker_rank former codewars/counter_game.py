import math
def who_wins(n):
    if n==1:
        return 'Richard'
    counter=0
    while n >1:
        counter += 1
        ans=math.log10(n) /math.log10(2)
        if int(ans) == ans:
            n=n//2
            
        else:
            nearest_pow=math.floor(math.log2(n))
            n -= 2**nearest_pow

    if counter%2==0:
        return 'Richard'
    return 'Louise'

print(who_wins(6))
