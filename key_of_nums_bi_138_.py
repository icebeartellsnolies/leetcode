def key_seq(num1, num2, num3):
    num1 = str(num1)
    num2 = str(num2)
    num3 = str(num3)
    if len(str(num1))<4:
        zeroes ='0'*( 4 - len(str(num1)))
        num1 = zeroes + str(num1)
        # print(num1)
    if len(str(num2))<4:
        zeroes = '0'*( 4 - len(str(num2)))
        num2 = zeroes + str(num2)
        # print(num2)
    if len(str(num3))<4:
        zeroes = '0'*( 4 - len(str(num3)))
        num3 = zeroes + str(num3)
        # print(num3)
    key = ''
    for i in range(4):
        key += str(min(int(num1[i]), int(num2[i]), int(num3[i])))
    return int(key)

# print(key_seq(1,10,1000))
print(key_seq(987, 879,789))