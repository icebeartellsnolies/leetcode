from itertools import combinations
length=int(input())
alph=list(input().split(' '))
to_check=int(input())

to_find='a'
score=0
combs=list(combinations(alph,to_check))
for each_comb in combs:
    if to_find in each_comb:
        score+=1

result=score/len(combs)
print(result)