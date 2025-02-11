# def single_number(nums):
#     i=0
#     while i <len(nums):
#         j=0
#         count=1
#         while j<len(nums):
#             if nums[i]==nums[j] and i!=j:
#                 count+=1
#             j+=1
#         if count==1:
#             return nums[i]
#         i+=1
# print(single_number([2,2,1]))

# CHATGPT'S CODE FOR REDUCING TIME COMPLEXITY
def single_number(nums):
    num_count = {}
    for num in nums:
        if num in num_count:
            num_count[num] += 1
        else:
            num_count[num] = 1
    
    for num, count in num_count.items():
        if count == 1:
            return num

# Example usage:
nums = [2, 2, 1, 1, 5]
print(single_number(nums))  # Output: 5

