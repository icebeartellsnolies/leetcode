def formatting(s,k):
    new_str = s.replace('-','')
    new_str = new_str.upper()
    pointer = len(new_str) - 1
    final_str = ''
    iterations = 0
    while pointer > -1:
        if iterations % k != 0 or iterations == 0:
            final_str = new_str[pointer] + final_str
            pointer -= 1
            iterations += 1
        else:
            final_str = '-' + final_str
            iterations = 0
    return final_str
# print(formatting("2-5g-3-J",2))
print(formatting("5F3Z-2e-9-w", 4))