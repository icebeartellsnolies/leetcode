def runner_ups(list_stu_marks):
    total_stu=len(list_stu_marks)
    marks=[]
    for i in range(total_stu):
        marks.append(list_stu_marks[i][1])
    for i in range(total_stu):
        j=i+1
        while j<total_stu:
            if marks[i]>marks[j]:
                marks[i],marks[j]=marks[j],marks[i]
            j=j+1
    smallest=marks[0]
    i=total_stu-1
    target_marks=None
    i=0
    while i<total_stu:
        if marks[i]>smallest:
            target_marks=marks[i]
            break
        else:
            i=i+1
    for j in range(total_stu):
        if target_marks==list_stu_marks[j][1]:
            print(list_stu_marks[j][0])

runner_ups([['Harry', 37.21], ['Tina', 37.2], ['Akriti', 41], ['Harsh', 39], ['Berry', 37.21]])