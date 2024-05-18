c={'b','c','d'}
v={'a','e'}

def splits(string):
    ans = ''
    letter = len(string) - 1

    while letter >= 0:
        if string[letter] in c:
            inverted=string[letter - 2:letter + 1]
            ans +=  inverted[::-1]
            ans+= '.'
            letter -= 3
        else:
            inverted=string[ letter - 1:letter + 1]
            ans +=  inverted[::-1]
            ans += '.'
            letter -= 2
    result=ans[::-1]
    result = result.strip('.')
    return result
test_cases=int(input())
lengths=[]
strings=[]
for test_case in range(test_cases):
    lengths.append(int(input()))
    strings.append(input())
for test_case in strings:
    print(splits(test_case))
