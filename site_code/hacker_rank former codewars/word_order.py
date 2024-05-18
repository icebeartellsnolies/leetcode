words_count=int(input())
words=[]
for count in range(words_count):
    words.append(input())
unrepeated_words=[]
for word in range(len(words)):
    if words[word] not in unrepeated_words:
        unrepeated_words.append(words[word])
counts=[]
for i in range(len(unrepeated_words)):
    count=0
    for j in range((len(words))):
        if unrepeated_words[i]==words[j]:
            count+=1
    counts.append(count)
print(len(unrepeated_words))
for i in range(len(counts)):
    print(counts[i],end=' ')