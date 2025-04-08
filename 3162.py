def numberOfPairs(nums1, nums2, k) -> int:
        pairs=[]
        for i in range(len(nums1)):
            for j in range(len(nums2)):
                ans=(nums1[i]*k)%nums2[j]
             
                if ans==0 :
                    pair=(i,j)
                    swap=(j,i)
                    if pair not in pairs and swap not in pairs:
                        pairs.append(pair)
        return len(pairs)

print(numberOfPairs([1,2,4,12],[2,4],3))