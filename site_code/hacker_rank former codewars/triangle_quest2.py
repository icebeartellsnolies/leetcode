pattern=int(input())

store=''
old_store=''
stores=[]
for i in range(pattern):
    store+=str(i+1)
    if i!=0:
        old_store=stores[i-1][::-1]
    stores.append(store)
    print(store,end='')
    print(old_store)