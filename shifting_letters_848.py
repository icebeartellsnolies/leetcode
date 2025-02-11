def shiftingLetters(s,shifts):
    total = sum(shifts)
    new_str=''
    prev_sum=0
    for i in range(len(shifts)):
        pos=ord(s[i])-97+(total-prev_sum)
        character = chr((pos%26)+97)
        new_str+=character
        prev_sum+=shifts[i]
    return new_str

# print(shiftingLetters("abc",[3,5,9]))
# print(shiftingLetters('aaa',[1,2,3]))
print(shiftingLetters("bad",[10,20,30]))
print(shiftingLetters("ruu",[26,9,17]))
# # print(chr(128-97%26))
# print(31%26)
# print(chr(ord('b')+(17%26)))