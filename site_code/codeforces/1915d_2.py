c=['b','c','d']
v=['a','e']
def splits(string):
    ans = ''
    letter=len(string)-1
    while letter-1 >= 0:
        if string[letter] in c:
            ans+=string[letter:letter-3:-1]
            ans+='.'
            letter -= 3
        else:
            ans += string[letter:letter-2:-1]
            ans+='.'
            letter -= 2

    result= ans[::-1]
    result=result.strip('.')
    return result

print(splits('bacedbab'))

c = ['b', 'c', 'd']
v = ['a', 'e']

def splits(string):
    ans = ''
    letter = len(string) - 1

    while letter >= 0:
        if string[letter] in c:
            ans = string[letter - 2:letter + 1] + '.' + ans
            letter -= 3
        else:
            ans = string[ letter - 1:letter + 1] + '.' + ans
            letter -= 2

    result = ans.strip('.')
    return result

print(splits('bacedbab'))
