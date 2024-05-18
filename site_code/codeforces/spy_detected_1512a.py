num_test_cases=int(input())
lsts=[]
for i in range(num_test_cases):
    length=int(input())
    lst=list(map(int,input().split()))
    lsts.append(lst)
for each_list in range(len(lsts)):
    
    for member in range(len(lsts[each_list])):
        if member==len(lsts[each_list])-1:
            if lsts[each_list][member]!=lsts[each_list][member-1]:
               if lsts[each_list][member]!=lsts[each_list][0]:
                    index=member+1
        elif member==0:
            if lsts[each_list][member]!=lsts[each_list][member+1]:
                if lsts[each_list][member]!=lsts[each_list][member+2]:
                    index=member+1
        else:
            if lsts[each_list][member]!=lsts[each_list][member-1]:
                if lsts[each_list][member]!=lsts[each_list][member+1]:
                    index=member+1
                    
    print(index)
