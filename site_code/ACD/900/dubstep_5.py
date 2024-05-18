def recover(dubstep):
    words=dubstep.split('WUB')
    string=''
    for word in range(len(words)):
        if len(words[word])!=0:
            string=string+words[word]+' '
    string=string.strip()
    return string

print(recover('WUBWUBABC'))