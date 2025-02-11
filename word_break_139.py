def wordBreak( s, wordDict):
    trues=[]
    for i in range(len(wordDict)):
        word=wordDict[i]
        len_word=len(word)
       
        for j in range(i,(len(s)-len_word)+1):
            check_word=s[j:j+len_word]
            if word==check_word:
                trues.append(True)
                break
    if len(trues)==len(wordDict):
        return True
    else:
        return False

print(wordBreak("applepenapple",["apple","pen"]))