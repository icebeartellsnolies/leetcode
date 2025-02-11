def is_happy(n):
    result=0
    ans=[]
    while True:
        for i in str(n):
            result+=(int(i)**2)
        if result==1:
            return True
        ans.append(result)
        n=result
        result=0
        if len(set(ans))!=len(ans):
            return False

print(is_happy(2))