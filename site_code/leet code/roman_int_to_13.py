def roman_to_int(num):
    roman=['I','V','X','L','C','D','M']
    numerals=[1,5,10,50,100,500,1000]
    decimal_repr=[]
    indices=[]
    
    for i in range(len(num)):
        for j in range(len(roman)):
            if num[i]==roman[j]:
                indices.append(j)
    for i in range(len(indices)):
        decimal_repr.append(numerals[indices[i]])
    digit=decimal_repr[-1]
    for i in range(len(decimal_repr)-2,-1,-1):
        if decimal_repr[i]<decimal_repr[i+1]:
            digit+=-decimal_repr[i]
        else:
            digit+=decimal_repr[i]
    return digit
print(roman_to_int("MCMXCIV"))