def areAlmostEqual(s1,s2):
    diff=0
    s_one=set()
    s_two=set()
    for i in range(len(s1)):
        if s1[i]!=s2[i]:
            diff+=1
            s_one.add(s1[i])
            s_two.add(s2[i])
    if diff==0:
        return True
    if diff==2 and s_one==s_two:
        return True
    return False

print(areAlmostEqual("bank","kanb"))
print(areAlmostEqual("attack","defend"))