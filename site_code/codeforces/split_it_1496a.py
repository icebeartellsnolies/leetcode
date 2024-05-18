test_cases=int(input())
ns=[]
ks=[]
strings=[]
for test_case in range(test_cases):
    n,k=(map(int,input().split()))
    ns.append(n)
    ks.append(k)
    strings.append(input().strip())
for test_case in range(test_cases):
    pointer2=-1
    k=ks[test_case]
    n=ns[test_case]
    string=strings[test_case]
    printed=False
    if k==0:
        print('YES')
        printed=True
    elif n<=k*2:
        print('NO')
        printed=True
    else:    
        for pointer1 in range(k):
            if string[pointer1] != string[pointer2]:
                print('NO')
                printed=True
                break
            pointer2 -= 1
        if printed==False:
            print('YES')
            