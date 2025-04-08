def arrangeCoins(n):
    levels=1
    while n>=levels:
        n-=levels
        levels+=1
    return levels-1

print(arrangeCoins(5))
