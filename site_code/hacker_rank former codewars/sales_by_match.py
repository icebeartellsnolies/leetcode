def sock_merchant(n,ar):
    unique = list(set(ar))
    pairs = 0
    for i in unique:
        count = ar.count(i)
        if count>=2:
            to_add = count//2
            pairs += to_add
        
    return pairs

print(sock_merchant(9,[10, 20, 20, 10, 10, 30, 50, 10, 20]))