# def merge(intervals):
#     all = [j for i in intervals for j in i]
#     pointer1=0
#     pointer2 =1
#     while pointer2 <  len(all):
#         if all[pointer2] <= all[pointer1]:
#             val1= all[pointer2]
#             val2 = all[pointer1]
#             all.remove(val1)
#             all.remove(val2)
#         pointer1 += 1
#         pointer2 += 1
#     merged=[]
#     for i in range(0,len(all)-1,2):
#         merged.append([all[i],all[i+1]])
#     return merged
def merge(intervals):
    intervals.sort(key=lambda i:i[0])
    output=[intervals[0]]
    for i in range(1,len(intervals)):
        
        if output[-1][1]>=intervals[i][0]:
            output[-1][1]=max(intervals[i][1],output[-1][1])
        else:
            new=[intervals[i][0],intervals[i][1]]
            output.append(new)
    return output

# print(merge([[1,4],[4,5]]))
# print(merge([[1,3],[2,6],[8,10],[15,18]]))
print(merge([[4,5],[1,4],[0,1]]))