from itertools import combinations

def non_div_ss(k,s):
    non_div=[]
    # for i in range(len(s)-1):
    comb=list(combinations(s,5))
    for j in comb:
        is_div=False
        for m in range(len(j)):
            for l in range(len(j)):
                if m!=l:
                    if (j[m]+j[l])%k==0:
                        is_div=True
                        break
        if is_div==False:
            non_div.append(j)
    set_is_div=non_div
    to_return=set_is_div[0]
    for i in set_is_div:
        if len(i)>len(to_return):
            to_return=i
    return len(to_return)

print(non_div_ss(5,[2, 7, 12 ,17, 22]))