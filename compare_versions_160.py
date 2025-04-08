def compare(version1, version2):
    v1 = version1.split('.')
    v2 = version2.split('.')
    v1 = list(map(int, v1))
    v2 = list(map(int, v2))
    num = 0
    while num < len(v1) and num < len(v2):
        if int(v1[num]) > int(v2[num]):
            return 1
        elif int(v1[num]) < int(v2[num]):
            return -1
        num += 1
    non_zeroes_1 = len(v1) - v1.count(0) - num
    non_zeroes_2 = len(v2) - v2.count(0) - num
    if non_zeroes_1> non_zeroes_2:
        return 1
    elif non_zeroes_1 < non_zeroes_2:
        return -1
    else:
        return 0
    # if num1 < num2:
    #     return -1
    # elif num1 > num2:
    #     return 1
    # else:
    #     return 0

# print(compare('1.2','1.10'))
# print(compare("7.5.2.4","7.5.3"))
print(compare("1.0.1","1"))