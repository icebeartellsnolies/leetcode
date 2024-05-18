from random import randint

cols = 4
rows = 5

m = [[0 for c in range(cols)] for r in range(rows)]
for c in range(cols):
    for r in range(rows):
        m[r][c] = randint(1, 10)

print(m)

sum = [None] * 5

for c in range(cols):
    for r in range(rows):
        for j in range(len(sum)):  # Limit iterations to the length of 'sum'
            if j == 0:
                sum[j] = 0
            sum[j] += m[r][c]

print(sum)