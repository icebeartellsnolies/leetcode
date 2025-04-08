def insert(intervals,newInterval):
    output=[]
    i=0
    while i < len(intervals):
        curr=intervals[i]
        if intervals[i][0]<newInterval[0]:
            while newInterval[1]>intervals[i][1]:
                i+=1
            else:
                new=[curr[0],newInterval[1]]
                output.append(new)
        else:
            output.append(intervals[i])
            i+=1
    return output
# intervals=[[1,3],[6,9]]
# newInterval = [2,5]
intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]]
newInterval = [4,8]
print(insert(intervals, newInterval))