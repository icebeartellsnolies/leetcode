def first_occurence(haystack,needle):
    needle_len=len(needle)
    index=-1
    for i in range(len(haystack)):
        word=haystack[i:i+needle_len]
        if word==needle:
            index= i
            return index
    return index 
print(first_occurence("leetcode","leeto"))
