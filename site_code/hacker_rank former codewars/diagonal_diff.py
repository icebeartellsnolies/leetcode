def diagonal_difference(arr):
    rows=cols=len(arr)
    main_dia=[0]*rows
    other_dia=[0]*rows

    sum1=0
    sum2=0
    for main_entry in range(rows):
        main_dia[main_entry]=arr[main_entry][main_entry]
        sum1+=main_dia[main_entry]

    for other_entry in range(rows):
        other_dia[other_entry]=arr[other_entry][cols-1]
        sum2+=other_dia[other_entry]
        cols-=1

    diff = abs(sum2-sum1)
    return diff

print(diagonal_difference([[11,2,4],[4,5,6],[10,8,-12]]))

    