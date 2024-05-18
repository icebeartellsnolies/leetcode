word_count=int(input())
words=list(input().split())
vowels=' a, e, i, o, u, y'
scores=[]
for word in range(word_count):
    score=0
    for letter in range(len(words[word])):
        if words[word][letter] in vowels:
            score+=1
    scores.append(score)

sum_score=0
for i in range(len(scores)):
    if scores[i]%2==0:
        sum_score+=2
    else:
        sum_score+=1
print(sum_score)