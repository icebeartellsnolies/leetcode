def is_additive_num(num):
    for p1 in range(len(str(num))-2):
        for p2 in range(p1+1,len(str(num))-1):
            p3=p2+1
            if int(num[p1])+int(num[p2]) != int(num[p3]):
                return False
            else:
                break
    
    return True

print(is_additive_num("199100199"))