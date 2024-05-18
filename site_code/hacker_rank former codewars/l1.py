def numberOfAlternatingGroups(colors):
    length=len(colors)
    groups=0
    for i in range(length):
        if colors[i-1] == colors[((i+1)%length)] and colors[i-1]!=colors[i]:
            groups+=1
    return groups

print(numberOfAlternatingGroups([1,1,1]))