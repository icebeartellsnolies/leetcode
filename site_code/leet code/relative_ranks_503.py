def relative_ranks(score):
    ans = [None]*len(score)
    for i in range(len(score)):
        if i==0:
            ans[i] = 'Gold Medal'
        elif i==1:
            ans[i] = 'Silver Medal'
        elif i==2:
            ans[i] = 'Bronze Medal'
        else:
            ans[i] = str(i+1)
    return ans

print(relative_ranks([5,4,3,2,1]))