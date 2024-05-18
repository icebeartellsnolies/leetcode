def min_moves(initial,target):
    count=0
    difference=target-initial
    if difference>0:
        if difference<=10:
            count=1
        else:
            original_difference=difference
            while difference>10:
                difference=int(difference-10)
                count+=1
            if original_difference-difference!=0:
                count+=1

    elif difference<0:
        if difference>=-10:
            count=1
        else:
            original_difference=difference
            while difference<-10:
                difference=int(difference+10)
                count+=1
            if original_difference-difference!=0:
                count+=1
    return count

print(min_moves(100500 ,9000))

