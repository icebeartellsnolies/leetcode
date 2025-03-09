def coloredCells(n):
    count=n
    n=1
    i=0
    while count>=1:
        n=(i*4)+n
        count-=1
        i+=1
    return n

print(coloredCells(2))