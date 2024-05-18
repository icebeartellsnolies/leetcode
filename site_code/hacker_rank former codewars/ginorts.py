word=input()
   
lowercase=[]
for letter in range(len(word)):
    if ord(word[letter])>=97 and ord(word[letter])<=123:
        lowercase.append(word[letter])
uppercase=[]
for letter in range(len(word)):
    if ord(word[letter])>=65 and ord(word[letter])<=91:
        uppercase.append(word[letter])

even=[]
odd=[]
for num in range(len(word)):
    if ord(word[num])>=48 and ord(word[num])<=57 :
        if int(word[num])%2==0:
            even.append(word[num])
        else:
            odd.append(word[num])
for i in range(len(even)):
    for j in range(len(even)):
        if even[i]<even[j]:
            even[i],even[j]=even[j],even[i]

for i in range(len(odd)):
    for j in range(len(odd)):
        if odd[i]<odd[j]:
            odd[i],odd[j]=odd[j],odd[i]

even_str=''
odd_str=''

for i in range(len(even)):
    even_str+=even[i]
for i in range(len(odd)):
    odd_str+=odd[i]

numbers=odd_str+even_str

for i in range(len(uppercase)):
    for j in range(len(uppercase)):
        if uppercase[i]<uppercase[j]:
            uppercase[i],uppercase[j]=uppercase[j],uppercase[i]

for i in range(len(lowercase)):
    for j in range(len(lowercase)):
        if lowercase[i]<lowercase[j]:
            lowercase[i],lowercase[j]=lowercase[j],lowercase[i]

final_str=''
final=lowercase+uppercase
for i in range(len(final)):
    final_str+=final[i]
print (final_str+numbers)

