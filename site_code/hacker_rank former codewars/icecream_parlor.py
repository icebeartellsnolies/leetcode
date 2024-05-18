def icecreamParlor(m, arr):
    for i in range(len(arr)):
        for j in range(i+1,len(arr)):
            if m==arr[i]+arr[j]:
                to_return=[i+1,j+1]
                return to_return
            
print(icecreamParlor(4, [2 ,2 ,4 ,3]))