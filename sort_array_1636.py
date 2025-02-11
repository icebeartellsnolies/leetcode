from collections import Counter
# def sorting(nums):
#     mapped = Counter(nums)
#     sorted_arr = sorted(mapped.items() , key= lambda x:x[1])
#     print(sorted_arr)
#     to_return=[]
#     for entry in range(len(sorted_arr)):
#         for times in range(sorted_arr[entry][1]):
#             to_return.append(sorted_arr[entry][0])
#     return to_return
def frequencySort(nums):
    
    frequency_map = Counter(nums)

    nums.sort(key=lambda x: (frequency_map[x], -x))
    return nums

print(frequencySort([1,1,2,2,2,3]))
# print()
# print(sorting([2,3,1,3,2]))
# print()
# print(sorting([-1,1,-6,4,5,-6,1,4,1]))