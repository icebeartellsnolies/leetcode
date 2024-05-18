from collections import Counter
def freq_sort(s):
    c = dict(Counter(s))
    c = sorted(c,key=lambda x : x[1])
    return c

print(freq_sort('tree'))