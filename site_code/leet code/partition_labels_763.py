def partitionLabels(s):
    hash_map={
    'a': -1, 'b': -1, 'c': -1, 'd': -1, 'e': -1, 'f': -1, 'g': -1, 'h': -1, 'i': -1, 'j': -1, 
    'k': -1, 'l': -1, 'm': -1, 'n': -1, 'o': -1, 'p': -1, 'q': -1, 'r': -1, 's': -1, 't': -1, 
    'u': -1, 'v': -1, 'w': -1, 'x': -1, 'y': -1, 'z': -1
    }
    ans=[]
    for i in range(len(s)):
        if hash_map[s[i]]==-1:
            ans.append(1)
            hash_map[s[i]]=len(ans)-1
        else:
            ans.append(1)
            loc=hash_map[s[i]]
            end=len(ans)-1
            sum=0
            for j in range(end,loc,-1):
                sum+=ans[j]
                del ans[j]
            ans[loc]=ans[loc]+sum
    
    return ans

print(partitionLabels("eccbbbbdec"))