number_of_cases=int(input())
words=input().split()
sets=[]
for word in words:
    set_word=set(word)
    if set_word not in sets:
        sets.append(set_word)
print(len(sets))