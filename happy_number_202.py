def is_happy(n):
    result=0
    for j in range(2**31):
        for i in (str(n)):
            result+=(int(i)**2)
        n=result
        if result==1:
            return True
        result=0
    return False

print(is_happy(2))