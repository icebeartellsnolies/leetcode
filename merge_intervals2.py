from itertools import product
def merge(intervals):
    final=[]
    if len(intervals)>1:
        for i in range(len(intervals)):
                for j in range(i+1,len(intervals)):
                    if intervals[i][0]>intervals[j][0]:
                        intervals[i],intervals[j]=intervals[j],intervals[i]
        all_intervals=[]
        for i in range(len(intervals)):
            for j in range(2):
                all_intervals.append(intervals[i][j])
        min_v=min(all_intervals)
        max_v=max(all_intervals)
        in_bw=False
        in_bws=[]
        for i in range(min_v,max_v+1):
            if i in all_intervals:
                 in_bws.append(True)
            else:
                 in_bws.append(False)
        if False not in in_bws:
             in_bw=True
        if in_bw==True:
             sub=[min_v,max_v]
             final.append(sub)
             
        if in_bw==False:
            
            i=0
            while i < len(all_intervals):
                sub=[None]*2
                sub[0]=all_intervals[i]
                sub[1]=all_intervals[i+1]
                length=len(all_intervals)
                for j in range(i+1,length):
                    if sub[1]<=all_intervals[j]:
                        sub[1]=j
                        i=j
                        break
                i+=1
                final.append(sub)
            return final
                    
    
print(merge([[1,4],[0,4]]))