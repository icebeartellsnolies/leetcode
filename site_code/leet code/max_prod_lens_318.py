def max_product(words):
    max_len = 0
    for i in range(len(words)):
        for j in range(i+1,len(words)):
            if set(words[i]).isdisjoint(set(words[j])):
                new_len=len(words[i]) * len(words[j])
                if new_len > max_len:
                    max_len = new_len
    return max_len

print(max_product(["a","aa","aaa","aaaa"]))