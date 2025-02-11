def int_to_roman(num):
    roman=['I','IV','V','IX','X','XL','L','XC','C','CD','D','CM','M']
    numerals=[1,4,5,9,10,40,50,90,100,400,500,900,1000]
    for i in range(len(numerals)-1,-1,-1):
        if num%numerals[i]!=num:
            less_than_num=numerals[i]
            roman_repr=roman[i]
            next_loop_val=i
            break
    to_subtract=num
    to_subtract=to_subtract-less_than_num
    main_str=roman_repr
    while to_subtract>0:
        for i in range(next_loop_val,-1,-1):
            if to_subtract>=numerals[i]:
                to_subtract-=numerals[i]
                main_str+=roman[i]
                break
    return main_str
print(int_to_roman(1974))