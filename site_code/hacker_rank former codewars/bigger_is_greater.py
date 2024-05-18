from itertools import permutations
def find_position(s):
    alphabets=["a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z"]
    position=0
    for j in range(len(alphabets)):
        if alphabets[j]==s:
            position=j+1
    return position

def greater(w):
    to_return='no answer'
    permutes= list(permutations(w))
    positions=[]
    combinatins=[]
    map1={}
    map2={}
    for i in permutes:
        position=[]
        string=''
        for j in range(len(i)):
            string+=i[j]
            position.append(find_position(i[j]))
        position=tuple(position)
        map1[string]=position
        map2[position]=string
        
        combinatins.append(string)
        positions.append(position)

    our_position=map1.get(w)
    positions.sort()
    for i in positions:
        if our_position<i:
            to_return= map2.get(i)
            break

    return to_return
    
print(greater('bb'))
