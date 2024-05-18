def merge_the_tools(string, k):
    start=0
    words=[]
    for end in range(k,len(string)+1,k):
        word=string[start:end]
        words.append(word)
        start+=k
    for i in range(len(words)):
        words[i]=words[i]
    for each_word in range(len(words)):
        new_word=''
        for letter in range(len(words[each_word])):
            if words[each_word][letter] not in new_word:
                new_word+=words[each_word][letter]
        words[each_word]=new_word

    for i in range(len(words)):
        print( words[i])

merge_the_tools('AABCAAADA',3)
