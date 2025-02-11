def findMedianSortedArrays(nums1, nums2):
    sorted=nums1+nums2
    sorted.sort()
    if len(sorted)>1:
        if len(sorted)%2==0:
            index1=len(sorted)//2
            index2=index1-1
            median=(sorted[index1]+sorted[index2])/2
        else:
            index1=len(sorted)//2
            median=float(sorted[index1])
    else:
        median=float(sorted[0])
    return median
print(findMedianSortedArrays([1,2],[3,4]))