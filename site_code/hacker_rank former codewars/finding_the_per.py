def find_avg(inp):
    arr=list(inp)
    to_find=arr[-1]
    len_arr=arr[0]
    names=[]
    for i in range(1,len_arr-1):
        entery=arr[i]
        names.append(entery)
    return names
print(find_avg(
'3'
'Krishna 67 68 69'
'Arjun 70 98 63'
'Malika 52 56 60'
'Malika'))