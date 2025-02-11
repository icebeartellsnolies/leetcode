from itertools import product
def letterCombinations(digits):
    if digits=='':
        return []
    alphabets=['abc','def','ghi','jkl','mno','pqrs','tuv','wxyz']
    indices=[]
    str_digits=str(digits)
    for i in range(len(str_digits)):
        indices.append(int(str_digits[i])-2)
    to_comb=[]
    for i in range(len(indices)):
        to_comb.append(alphabets[indices[int(i)]])
    combinations=list(product(*to_comb))
    result=[]
    for comb in range(len(combinations)):
        word=''
        for j in range(len(combinations[comb])):
            word+=combinations[comb][j]
        result.append(word)
    return result
print(letterCombinations(''))