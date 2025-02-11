def can_finish(num_courses, prereq):
    capita_prereq=[]
    corr_courses=[]
    for pair in range(len(prereq)):
        capita_prereq.append(prereq[pair][1])
        corr_courses.append(prereq[pair][0])
    
    if len(capita_prereq)>num_courses:
        return False
    elif len(capita_prereq)<num_courses:
        return True
    else:
        combined=set(capita_prereq+corr_courses)
        set_capita=set(capita_prereq)
        if combined==set_capita:
            return True
        else:
            return False

print(can_finish(2,[[1,0],[0,1]]))

