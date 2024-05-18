def piling(length, width):
    area=length*width
    num_dominos=area//2
    return num_dominos
x,y=map(int, input().split())
print(piling(x,y))