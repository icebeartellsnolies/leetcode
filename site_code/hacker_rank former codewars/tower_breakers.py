def tower_breakers(n, m):
    if m==1:
        return 2
    elif n%2==0:
        return 2
    elif n%2!=0:
        return 1