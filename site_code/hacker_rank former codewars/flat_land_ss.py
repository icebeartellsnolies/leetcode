def flat_land(n,c):
    all_cities=[]
    for i in range(n):
        all_cities.append(i)

    distances=[all_cities[-1]]*n

    for i in range(len(c)):
        for j in range(n):
            diff=abs(c[i]-all_cities[j])
            if diff<distances[j]:
                distances[j]=diff
    
    return max(distances)

print(flat_land(5,[0  ,4 ]))