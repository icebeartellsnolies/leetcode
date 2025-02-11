# NOTE: my brute force solution:
# def frequent(nums,k):
#     distinct=[]
#     for i in nums:
#         if i not in distinct:
#             distinct.append(i)
#     counts=[]
#     for i in distinct:
#         counts.append([nums.count(i),i])
#     counts.sort()
    
#     to_return=[]
#     for i in range(len(counts)-1,-1,-1):
#         if len(to_return)<k:
#             to_return.append(counts[i][1])
#         else:
#             break
    
#     return to_return
from collections import Counter
def frequent(nums, k):
    counts = Counter(nums)
    counts = list(counts.items())
    print(counts)
    counts.sort(key=lambda x:x[1])
    print(counts)
    final_list = []
    for pair in range(len(counts)-1,-1,-1):
        if len(final_list)<k:
            final_list.append(counts[pair][0])
        else:
            break
    return final_list
# print(frequent([1],1))
print(frequent([1,1,1,2,2,3],2))
# print(frequent([3,0,1,0],1))