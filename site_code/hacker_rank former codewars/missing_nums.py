def missing(arr,brr):
    missed=[]
    for i in arr:
        if i in brr:
            brr.remove(i)
        else:
            missed.append(i)
    ans=list(set(missed+brr))
    ans.sort()
    return ans
