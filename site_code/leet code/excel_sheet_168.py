def convert_to_title(columnNumber):
    alphabets=["A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z"]
    if columnNumber<27:
        return alphabets[columnNumber-1]
    else:
        removed=0
        
        while columnNumber>26:
            columnNumber-=26
            removed+=1
        # if removed>26:
        #     while removed>26:

        string=alphabets[removed-1]+alphabets[columnNumber-1]
        return string

print(convert_to_title(720))

print(701%6)