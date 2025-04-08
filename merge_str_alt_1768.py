def alt_merge(word1,word2):
    concatenated = ''
    letter = 0
    while letter<len(word1) and letter<len(word2):
        concatenated += word1[letter]
        concatenated += word2[letter]
        letter += 1
    bigger = word2
    if len(word2)<len(word1):
        bigger = word1
    rest = bigger[letter:]
    concatenated += rest
    return concatenated

# print(alt_merge('abc','pqr'))
print(alt_merge('abcd','pq'))