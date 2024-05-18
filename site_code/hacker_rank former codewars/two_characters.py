from itertools import combinations
# string= 'abaacdabd'
# unique = 'abcd'

# comb = list(combinations(unique,2))
# print(comb)
def is_alternating(string):
    for i in range(len(string)-1):
        if string[i] == string[i+1]:
            return False
    return True

def max_length(s):
    
    unique = list(set(s))
    if len(unique) < 2:
        return 0
    comb = list(combinations((unique),len(unique)-2))
    alternates = []
    for i in range(len(comb)):
        copy_s=s
        for j in range(len(comb[i])):
            copy_s = copy_s.replace(comb[i][j],'')
        to_append = is_alternating(copy_s)
        if to_append:
            alternates.append(copy_s)
    max_length=0
    for i in alternates:
        if len(i)>max_length:
            max_length = len(i)
    return max_length

# print(max_length('asdcbsdcagfsdbgdfanfghbsfdab'))
print(max_length('aaaaa'))
# s='abaacdabd'
# unique = list(set(s))
# comb = list(combinations((unique),2))
# for i in range(len(comb)):
#     copy_s=s
#     for j in range(len(comb[i])):
#         copy_s = copy_s.replace(comb[i][j],'')
#     print(copy_s)
        