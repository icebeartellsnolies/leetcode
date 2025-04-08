def convert_str(s,k):
    int_s = ''
    for i,letter in enumerate(s):
        int_s += str(ord(letter) - 96)
    for iteration in range(k):
        total = 0
        for pointer in range(len(str(int_s))):
            total += int(int_s[pointer])
        int_s = str(total)

    return int(total)

print(convert_str('iiii',1))
print(convert_str('leetcode',2))