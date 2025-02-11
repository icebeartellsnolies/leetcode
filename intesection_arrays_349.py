def intersection(nums1,nums2):
    answer=[]
    if len(nums1)>len(nums2):
        longest=nums1
        shortest=nums2
    else:
        longest=nums2
        shortest=nums1
    for i in shortest:
        if i in longest and i not in answer:
            answer.append(i)
    return answer

print(intersection([4,9,5],[9,4,9,8,4]))