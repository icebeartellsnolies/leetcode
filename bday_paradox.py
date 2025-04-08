import math
def paradox(n,k):
    f=math.factorial
    deno=(f(k)*f(n-k))
    return f(n)/deno
print(paradox(23,2))