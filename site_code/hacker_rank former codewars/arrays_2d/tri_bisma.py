rows=5
i=0
cols=5
a=[1,2,3,4,5,6,7,8,9,10]
for r in range(rows):
    for s in range(rows-r):
        print(' ', end=' ')
    for c in range(r):
        print(a[i], end=' ')
        i=i+1
    print()