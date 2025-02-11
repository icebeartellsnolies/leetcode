import copy
def longestPalindromeSubseq(s):
    def check_palindrome(string):
        rev=string[::-1]
        return rev==string
    if len(s)>1:
        sequences=[]
        for pointer1 in range(len(s)):
            for pointer2 in range(len(s)-1,-1,-1):
                if pointer2>pointer1:
                    if s[pointer1]==s[pointer2]:
                        sequence=s[pointer1:pointer2+1]
                        sequences.append(sequence)
        if len(sequences)==0:
            return 1
        palindromes=[]
        for seq in (sequences):
            is_palindromic=check_palindrome(seq)
            if is_palindromic==True:
                palindromes.append(seq)
            letter=0
            while is_palindromic==False:
                
                while letter<(len(seq)):
                    copy_seq=list(copy.deepcopy(seq))
                    copy_seq.pop(letter)
                    if check_palindrome(copy_seq)==True:
                        to_append=''
                        for i in range(len(copy_seq)):
                            to_append+=copy_seq[i]
                        palindromes.append(to_append)
                        is_palindromic=True
                        break
                    else:
                        letter+=1
                        break
                if letter==len(seq):
                    is_palindromic=True

        longest=palindromes[0]
        for palin in range(len(palindromes)):
            if len(palindromes[palin])>len(longest):
                longest=palindromes[palin]
        length=(len(longest)) 
    else:
        length=len(s)
    return length
print(longestPalindromeSubseq("abcabcabcabc"))