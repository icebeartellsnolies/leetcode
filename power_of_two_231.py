def isPowerOfTwo(n) :
    for i in range(31):
        ans = 2 ** i
        if ans == n:
            return True
    return False