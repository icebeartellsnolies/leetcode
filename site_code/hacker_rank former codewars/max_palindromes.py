from itertools import permutations
def query(s,l,r):
    to_check=s[l-1:r]
    max_lengths=[]
    checking=to_check
    for i in range(len(to_check)):
        checking_lst=list(to_check)
        checking_lst.pop(i)
        checking=''.join(k for k in checking_lst)

        comb=list(permutations(checking,len(checking)))

        for j in comb:
            reversed_comb=j[::-1]
            if reversed_comb==j:
                string=''.join(k for k in j)
                max_lengths.append(string)
    
    un_duplicated=[]
    for i in max_lengths:
        if i not in un_duplicated:
            un_duplicated.append(i)
    return len(un_duplicated)

print(query('abab',1,4))
