def remove_duplicates(nums):
    i=0
    final=[]
    while i<len(nums):
        sub_arr=[nums[i]]
        count=1
        occurence=1
        j=i+1
        while j<len(nums):
            if nums[i]==nums[j]:
                occurence+=1
                if count<2:
                    sub_arr.append(nums[j])
                    count+=1
            j+=1
        i+=occurence
        final.extend(sub_arr)
    return final
print(remove_duplicates([1,1,1,2,2,3]))