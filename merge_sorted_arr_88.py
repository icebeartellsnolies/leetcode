def merge(nums1, m, nums2, n):
    j=0
    for i in range(len(nums1)-1,-1,-1):
        if j < n:
            nums1[i]=nums2[j]
        else:
            break
        j += 1
    nums1.sort()
    return nums1
# print(merge([1,2,3,0,0,0],3,[2,5,6],3))
# print(merge([0],0,[1],1))
# print(merge([-1,0,0,3,3,3,0,0,0],6, [1,2,2],3))
print(merge([-1,-1,0,0,0,0],4,[-1,0],2))