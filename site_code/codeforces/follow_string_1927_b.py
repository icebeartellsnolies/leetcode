import copy
num_test_cases=int(input())
traces=[]
for i in range(num_test_cases):
    length=int(input())
    trace=list(map(int,input().split()))
    traces.append(trace)
alphabets=["a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z"]

for trace in range(num_test_cases):
    string=''
    new_count=copy.deepcopy(traces[trace])
    for letter in range(0,len(traces[trace])):
        if new_count[letter]==0:
            string+=alphabets[letter]
            new_count[letter]+=1
        else:
            zero=letter-1
            while zero >=0:
                if zero>=1:
                    if new_count[letter]==new_count[zero]:
                        string+=string[zero]
                        new_count[letter]+=1
                        for update in range(zero,-1,-1):
                            if string[letter]==string[update]:
                                new_count[update]=new_count[letter]
                        break
                else:
                    string+=string[0]
                    new_count[1]+=1
                    new_count[0]=new_count[letter]
                    break
                zero-=1
    print(string)
 
# 8
# 0 1 0 1 2 3 2 4
# aacccccc
# yyqqyyqy
# 7
# 0 0 1 0 1 1 2
# abaddaa
# bubxuxb

