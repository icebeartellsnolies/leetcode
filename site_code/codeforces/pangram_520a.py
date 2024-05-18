length=int(input())
sentence=input()
alphabets={"a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z"}
string=set()
sentence=sentence.lower()
for letter in range(len(sentence)):
    string.add(sentence[letter])
if string==alphabets:
    print(True)
else:
    print(False)