def nextGreaterElement( nums1,nums2):
    greater=dict()
    ans=[]
    stack=[]
    for i in range(len(nums2)-1,-1,-1):
        while stack:
            if stack[-1]>nums2[i]:
                greater[nums2[i]]=stack[-1]
                stack.append(nums2[i])
                break
            else:
                stack.pop()
        if not stack:
            greater[nums2[i]]=-1
            stack.append(nums2[i])

    for i in range(len(nums1)):
        ans.append(greater[nums1[i]])
    return ans

print(nextGreaterElement([4,1,2],[1,3,4,2]))
