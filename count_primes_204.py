def is_prime(n):
    for i in range(n-1,1,-1):
        if n%i==0:
            return False
    return True

def count_primes(n):
    no_of_primes=0
    for i in range(n-1,1,-1):
        is_i_prime=is_prime(i)
        if is_i_prime==True:
            no_of_primes+=1
    return no_of_primes

print(count_primes(7))
