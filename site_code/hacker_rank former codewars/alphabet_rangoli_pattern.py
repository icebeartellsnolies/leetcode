def rangoli(integer):
    integer=int(integer)
    alphabets=["a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z"
]
    alph=[]
    for i in range(integer-1,-1,-1):
        alph.append(alphabets[i])
    size=(integer*2)-1
    store=''
    old_store=''

    for i in range(integer):
        print('-'*(size-1),end='')
        store=store+alph[i]
        
        if i!=0:
            old_store=old_store+alph[i-1]
        for j in range(len(store)):
            if j!=len(store)-1:
                print(store[j],end='-')
            else:
                print(store[j],end='')
        for k in range(len(old_store)):
            if k==0:
                print('-',end='')
            if k!=len(old_store)-1:
                print(old_store[k],end='-')
            else:
                print(old_store[k],end='')
        print('-'*(size-1))
        size=size-2
    
    size=size+2
    
    for i in range(integer-1):
        store=''
        old_store=''
        print('-'*(size+1),end='')
        for j in range(integer-i-1):
            store=store+alph[j]
        
        if i!=(integer-1):
            for j in range(integer-i-2):
                old_store=old_store=old_store+alph[j]
        for j in range(len(store)):
            if j!=len(store)-1:
                print(store[j],end='-')
            else:
                print(store[j],end='')
        for k in range(len(old_store)):
            if k==0:
                print('-',end='')
            if k!=len(old_store)-1:
                print(old_store[k],end='-')
            else:
                print(old_store[k],end='')
        print('-'*(size+1))
        size=size+2

rangoli(7)