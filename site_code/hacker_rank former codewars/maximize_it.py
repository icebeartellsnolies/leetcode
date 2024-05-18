from itertools import product
ls_size,dividend=map(int,input().split())
lists=[]
for i in range(ls_size):
    user_inputs_list = input().split()
    result_list = list(map(int, user_inputs_list))
    lists.append(result_list)
modified=[]
for i in range(len(lists)):
    modified.append(lists[i][1:])
combinations = list(product(*modified))

eqs=[]

for i in range(len(combinations)):
    eq=0
    for j in range(len(combinations[i])):
        eq=eq+(combinations[i][j]**2)
    eqs.append(eq)

moduled=[]
for num in eqs:
    moduled.append(num%dividend)

for i in range(len(moduled)):
    for j in range(i+1, len(moduled)):
        if moduled[i]<moduled[j]:
            moduled[i],moduled[j]=moduled[j],moduled[i]

print(moduled[0])
