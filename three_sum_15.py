def three_sums(nums):
    answers=[]
    
    for i in range(len(nums)):
        check=[i]
        for j in range(i+1,len(nums)):
            if i!=j:
                check=[i,j]
                for k in range(j+1,len(nums)):
                    if i!=j and j!=k and k!=i:
                        check=[i,j,k]
                        if nums[i]+nums[j]+nums[k]==0:
                            answers.append(check)
    results=[]
    for i in answers:
        r=[]
        for j in i:
            r.append(nums[j])
        results.append(r)                    
    
    for i in results:
        i.sort()
    
    final_results=[]
    for i in results:
        if i not in final_results:
            final_results.append(i)
    return final_results

print(three_sums([0,0,0]))
