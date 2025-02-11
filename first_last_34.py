# NOTE:Brute force solution
# def search_range(nums, target):
#     indices=[-1,-1]
#     length=len(nums)
#     for num in range(len(nums)):
#         if nums[num]==target:
#             if nums[(num+1)%length]==target and length>1:
            
#                 indices=[num,num+1]
#                 break
#             else:
#                 indices=[num,num]
#                 break
#     return indices
# print(search_range([1],1))
# NOTE: Two pointer approach
def search_range(nums, target):
    if len(nums) == 0:
        return [-1,-1]
    if len(nums) == 1 :
        if target in nums:
            return [0,0]
        else:
            return [-1,-1]
    is_in = False
    pointer1 = 0
    pointer2 = 1
    while pointer2 < len(nums):
        if is_in == False:
            if nums[pointer1] == target:
                is_in = True
                if pointer1 != len(nums)-1:
                    if nums[pointer2] == target:
                        pointer2 += 1
                        continue
                    else:
                        return [pointer1,pointer1]
        

            
        if is_in == False:
            pointer1 += 1
            pointer2 += 1
    if is_in == False:
        if nums[-1] == target:
            return [len(nums)-1,len(nums)-1]
        else:
            return [-1,-1]

# print(search_range([1,4],4))
print(search_range([5,7,7,8,8,10],8))
# NOTE:BINARY SEARCH
def search_range(nums, target):
    def bin_search(nums, target, left_bias):
        low=0
        high=len(nums)-1
        i = -1

        while low<=high:
            mid=(low+high)//2
            if nums[mid] == target:
                if left_bias:
                    high=mid-1
                else:
                    low = mid + 1
            elif nums[mid]<target:
                low = mid + 1
            elif nums[mid]>target:
                high = mid - 1
        return i
# print(locate_cards([8, 8, 6, 6, 6, 6, 6, 6, 3, 2, 2, 2, 0, 0, 0],1))