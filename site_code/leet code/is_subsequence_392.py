import copy
def is_ss(s,t):
    indices=[]
    for i in range(len(s)):
        if s[i] not in t:
            return False
        else:
            if len(indices)==0:
                for j in range(len(t)):
                    if s[i]==t[j]:
                        indices.append(j)
                        break
            else:
                j=indices[-1]+1
                while j<len(t):
                    if s[i]==t[j]:
                        indices.append(j)
                        break
                    j+=1
                    
    if  len(s)==len(indices):
        return True
    else:
        return False

print(is_ss("ab","baab"))