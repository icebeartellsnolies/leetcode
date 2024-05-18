s=input()
distint=[]
for letter in range(len(s)):
    if s[letter] not in distint:
        distint.append(s[letter])
counts=[]
for i in range(len(distint)):
    count=0
    for j in range(len(s)):
        if distint[i]==s[j]:
            count+=1
    counts.append(count)
together=[]
for i in range(len(counts)):
    string=''
    string+=f'{distint[i]} {counts[i]}'
    together.append(string)

for i in range(len(counts)):
    for j in range(i+1,len(counts)):
        if counts[i]<counts[j]:
            counts[i],counts[j]=counts[j],counts[i]
three=0

for i in range(len(counts)):
    for j in range(len(together)):
        splitted=together[j].split()
        if counts[i]==int(splitted[1]) and three<3:
            print(together[j])
            three+=1