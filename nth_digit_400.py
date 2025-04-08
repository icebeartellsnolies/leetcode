def find_digit(n):
    string=''.join(str(i+1) for i in range(n+1))
    return int(string[n-1])

print(find_digit(11))
    