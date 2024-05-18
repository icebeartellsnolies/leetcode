from random import randint
cols=4
rows=5
m=[[0 for c in range(cols)] for r in range(rows)]
for c in range(cols):
    for r in range(rows):
        m[r][c]=randint(1,10)
print(m)
sum=[0]*rows
for c in range(cols):
    for r in range(rows):
        sum[r]=sum[r]+m[r][c]
print(sum)