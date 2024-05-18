# def is_isomorphic(s,t):

#     mapped=[]
#     for letter in range(len(s)):
#         sub=[s[letter],t[letter]]
#         mapped.append(sub)
#     for i in range(len(mapped)):
#         for j in range(i+1,len(mapped)):
#             if mapped[i][0]==mapped[j][0]:
#                 if mapped[i][1]!=mapped[j][1]:
#                     return False
#     return True 

# print(is_isomorphic("badc","bada"))
def is_isomorphic(s,t):
    map1 = dict(zip(s, t))
    map2 = dict(zip(t, s))
   
    string1 = ''
    string2 = ''
  
    for letter in range(len(s)):
        string1 += map1.get(s[letter])  
        string2 += map2.get(t[letter])

    if string1==t and string2==s:
        return True
    else:
        return False

print(is_isomorphic("egg","foo"))
