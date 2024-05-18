def long(string):
    length=len(string)
    final_word=string
    if length>=10:
        first_word=string[0]
        last_word=string[-1]
        mid_word=str(length-2)
        final_word=first_word+mid_word+last_word
    return final_word
x=input()
print(long(x))