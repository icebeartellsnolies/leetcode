def num_of_steps(coord):
    count=0
    while coord>=5:
        coord=coord-5
        count+=1
    if coord<5 and coord>0:
        count=count+1
    return count
x = int(input())
print(num_of_steps(x))