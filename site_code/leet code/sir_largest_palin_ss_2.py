import copy
def partition(s):
    sequences=[]
    for pointer1 in range(len(s)):
        for pointer2 in range(len(s)-1,-1,-1):
            if pointer2>pointer1:
                if s[pointer1]==s[pointer2]:
                    sequence=s[pointer1:pointer2+1]
                    sequences.append(sequence)
    length=len(sequences[0])
    if length%2==0:
        copy_seq=copy.deepcopy(sequences[0])
        half=length//2
        lst=list(copy_seq)
        mid=lst.pop(half-1)
        part1=lst[:half]
        part2=lst[half-1:length+1]
    return mid,part1,part2


def is_palindrome(string):
    rev_string=string[::-1]
    return string==rev_string

def logest_palindromic_ss(s):
    mid,part1,part2=partition(s)
    # kill1=False
    # kill2=False
    i=0
    while i<(len(part1)):
        if part1[i]!=part2[len(part2)-i-1]:
            popped=part1.pop(i)
            together=part1+part2
            if is_palindrome(together)==True:
                palindrome=together
                break
            else:
                part1.insert(i,popped)
                popped=part2.pop(len(part2)-i-1)
                together=part1+part2
                if is_palindrome(together)==True:
                    palindrome=together
                    break
        i+=1
    return palindrome
print(logest_palindromic_ss('abcabcabcabc'))