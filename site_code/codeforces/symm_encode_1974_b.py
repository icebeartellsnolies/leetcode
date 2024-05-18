cases=int(input())
for c in range(cases):
    length=int(input())
    string=input()
    lst=[]
    for i in string:
        lst.append(i)
    # lst.sort()
    # dictionary={}
    # reverse=lst[::-1]
    # for i in range(len(lst)):
    #     dictionary[lst[i]]=reverse[i]
    

    # reverse=distinct[::-1]
    reverse=lst[::-1]
    print(reverse)
