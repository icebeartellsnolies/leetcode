def weightedUniformStrings(s, queries):
    weights=[]
    for i in range(len(s)):
        seq=s[i]
        for j in range(i+1,len(s)):
            if s[i]==s[j]:
                seq+=s[j]
        weigth=0
        for k in seq:
            weigth+=ord(k)-97+1
        weights.append(weigth)

    answers=[]
    for i in queries:
        if i in weights:
            answers.append('Yes')
        else:
            answers.append('No')
    return answers
print(weightedUniformStrings('abbcccdddd',[1,7,5,4,15]))