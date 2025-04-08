def longest_palin(s):
    mapping = {}
    for letter in s:
        if letter in mapping:
            mapping[letter] += 1
        else:
            mapping[letter] = 1
    if len(mapping) == 1:
        return len(s)
    longest = 0
    odd_freq = 0
    even_len = False
    if len(s)%2 == 0:
        even_len = True 
    for key, freq in mapping.items():
        if freq % 2 == 0 :
            longest += freq
        if not even_len:
            if freq%2 == 1 and freq>odd_freq:
                if odd_freq == 0:
                    longest += freq
                    odd_freq = freq
                else:
                    longest -= odd_freq
                    longest += freq
                    odd_freq = freq

    return longest

print(longest_palin('abccccdd'))
print(longest_palin('a'))
print(longest_palin("bananas"))