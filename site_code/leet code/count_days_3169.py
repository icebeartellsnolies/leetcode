def countDays(days, meetings):
    meetings.sort()
    prev_end=0
    for m in meetings:
        end=max(m[0],prev_end+1)
        ln=m[1]-end+1
        if ln>0:
            days=days-ln
        prev_end= max(prev_end,m[1])
    return days

print(countDays(days = 5, meetings = [[2,4],[1,3]]))
print(countDays(days = 10, meetings = [[5,7],[1,3],[9,10]]))
print(countDays(days = 6, meetings = [[1,6]]))