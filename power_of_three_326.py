import math
def power_exist(n):
    if n<1:
        return False
    if n == 1:
        return True
    while n>1:
        n = n/3
        if int(n) == n:
            n = int(n)
        else:
            return False
    return True

print(power_exist(3))