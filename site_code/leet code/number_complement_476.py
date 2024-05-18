def inverse_num(num):
    comp_str = str(bin(num))[2:]
    complement = ''
    for digit in comp_str:
        if digit == '0':
            complement += '1'
        else:
            complement += '0'
    decimal_val = 0
    power = len(complement) - 1
    for i in complement:
        if i == '1':
            decimal_val += 2**power
        power -= 1
    return decimal_val

# print(inverse_num(5))
print(inverse_num(1))