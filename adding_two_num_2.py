def addTwoNumbers(l1, l2):
    real_l1=''
    length_l1=len(l1)
    for i in range(length_l1-1,-1,-1):
        real_l1=real_l1+str(l1[i])
    real_l2=''
    length_l2=len(l2)
    for i in range(length_l2-1,-1,-1):
        real_l2=real_l2+str(l2[i])
    ans=int(real_l1)+int(real_l2)
    r=[]
    ans=str(ans)
    l_ans=len(ans)
    for i in range((l_ans-1),-1,-1):
        r.append(int(ans[i]))
    return r
l1=[9,9,9,9,9,9,9]
l2=[9,9,9,9]
print(addTwoNumbers(l1,l2))
        