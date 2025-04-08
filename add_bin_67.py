def bin_add(a,b):
    a_bin=[]
    b_bin=[]
    result=''
    if len(a)>len(b):
        zeros=len(a)-len(b)
        for i in range(zeros):
            b_bin.append(0)
    elif len(b)>len(a):
        zeros=len(b)-len(a)
        for i in range(zeros):
            a_bin.append(0)
    for elem in range(len(a)):
        a_bin.append(int(a[elem]))
    for elem in range(len(b)):
        b_bin.append(int(b[elem]))
    for i in range(len(a_bin)-1,-1,-1):
        sum=a_bin[i]+b_bin[i]
        if sum==2 and i-1!=-1:
            result+=str(0)
            a_bin[i-1]+=1
        if sum==2 and i-1==-1:
            result+=str('01')
        if sum==1:
            result+=str(1)
        if sum==0:
            result+=str(0)
        if sum==3 and i-1!=-1:
            result+=str(1)
            a_bin[i-1]+=1
        if sum==3 and i-1==-1:
            result+=str('11')
    result=result[::-1]
    return result
print(bin_add("111",'1010'))