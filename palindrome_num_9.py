def is_palindrome(x):
    palindromic=False
    str_num=str(x)
    if x>=0:
        reversed=str_num[::-1]
        if reversed==str_num:
            palindromic=True
    
    return palindromic
print(is_palindrome(10))