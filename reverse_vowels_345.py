def reverse_vowels(s):
    vowels = {'a','e','i','o','u','A','E','I','O','U'}
    s = list(s)
    left = 0
    right = len(s) - 1
    while right > left:
        if s[right] in vowels and s[left] in vowels:
            s[right], s[left] = s[left], s[right]
            right -= 1
            left += 1
        elif s[right] in vowels:
            left += 1
        elif s[left] in vowels:
            right -= 1
        else:
            right -= 1
            left += 1
    return ''.join(s)

# print(reverse_vowels('leetcode'))
print(reverse_vowels('hello'))