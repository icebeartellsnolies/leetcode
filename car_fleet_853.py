def fleets(target, position, speed):
    group0 = False
    group_odd = False
    group_even = False
    for i in position:
        if i==0:
            group0 = True
        elif i%2 == 0:
            group_even = True
        else:
            group_odd = True
        if group0 and group_odd and group_even:
            return 3
    trues = [group0, group_even, group_odd]
    return trues.count(True)
# target = 10
# position = [3]
# speed = [3]
target = 12
position = [10,8,0,5,3]
speed = [2,4,1,1,3]
print(fleets(target, position, speed)) 