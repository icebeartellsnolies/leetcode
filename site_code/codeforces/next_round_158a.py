def advancers(total, min, scores):
    count=0
    for i in range(total):
        if scores[i]>min:
            count=count+1
    return count

grades=[0, 0, 0, 0]
print(advancers(4,2,grades))