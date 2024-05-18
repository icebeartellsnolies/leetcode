from collections import Counter
def anagram(s,t):
    if Counter(s) == Counter(t):
        return True
    else:
        return False
print(anagram('rat','car'))