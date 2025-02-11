def word_pattern(pattern,s):
    s_lst=s.split()
    if len(pattern)!=len(s_lst):
        return False
    else:
        mapping1=set(zip(pattern,s_lst))
        mapping2=list(zip(set(pattern),set(s_lst)))
        # return len(mapping1)==len(mapping2)
        return mapping1,mapping2
print(word_pattern("abba","dog cat cat dog"))