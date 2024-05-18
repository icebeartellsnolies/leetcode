def count_magical_str(n):
    magical_str = '122'
    i = 2
    while len(magical_str) < n:
        if magical_str[-1] == '1':
            magical_str += '2' * int(magical_str[i])
            
        else:
            magical_str += '1' * int(magical_str[i])

        i += 1
    str_to_check = magical_str[:n]        
    return str_to_check.count('1')

# print(count_magical_str(1))
print(count_magical_str(8))