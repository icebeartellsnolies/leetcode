# def product_except_self(nums):
#     answer=[]
#     for i in range(len(nums)):
#         result=1
#         for j in range(len(nums)):
#             if i==j:
#                 continue
#             else:
#                 result=result*nums[j]
#         answer.append(result)
#     return answer
def product_except_self(nums):
  left_product = []
  left_prod = 1

  for num in nums:
    left_product.append(left_prod)
    left_prod *= num
  print(left_product)
  right_prod = 1
  right_product=[1]*len(nums)

  for i in range(len(nums)-1, -1, -1):
    right_product[i] = right_prod
    right_prod *= nums[i]
  print(right_product)
  answer = []
  for i in range(len(nums)):
    answer.append( left_product[i] * right_product[i])
  return answer

# print(product_except_self([-1,1,0,-3,3]))
# print(product_except_self([0,0]))
# NOTE: GEMINI code not exceeding time limit
# def product_except_self(nums):

#   length = len(nums)
#   answer = [1] * length  # Initialize a list of 1s with the same length as nums

#   # Calculate the cumulative product from left to right
#   for i in range(1, length):
#     answer[i] = answer[i - 1] * nums[i - 1]

#   # Calculate the cumulative product from right to left and multiply with the left cumulative product
#   right_cumulative_product = 1
#   for i in range(length - 1, -1, -1):
#     answer[i] *= right_cumulative_product
#     right_cumulative_product *= nums[i]

#   return answer

# # Example usage
nums = [1, 2, 3, 4]
result = product_except_self(nums)
print(result)  # Output: [24, 12, 8, 6]


                
