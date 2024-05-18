from random import randint
rows=4
cols=4
a=[[0 for c in range(cols)] for r in range(rows)]
for c in range(cols):
    for r in range(rows):
        a[r][c]=randint(-5,5)

for r in range(rows):
    for c in range(cols):
        print(a[r][c], end='\t')
    print()
print('-----------------------------')
    # [i][j]
    # 0,0
    # 1,1
    # 2,2
    # 3,3
def diag_replace():
    for r in range(rows):
        for c in range(cols):
            if c==r:
                if a[r][c]<0:
                    a[r][c]=0
                else:
                    a[r][c]=1
        
    for r in range(rows):
        for c in range(cols):
            print(a[r][c], end='\t')
        print()
diag_replace()