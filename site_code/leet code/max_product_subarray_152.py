def max_product(nums):
    products=[]
    for pointer1 in range(len(nums)):
        for pointer2 in range(len(nums),pointer1,-1):
            new_arr=nums[pointer1:pointer2]
            if len(new_arr)>0:
                prod=new_arr[0]
                for i in range(1,len(new_arr)):
                    prod*=new_arr[i]
                products.append(prod)
    return max(products)
print(max_product([-2,0,-1]))

# CHATGPT UPDATED VERSION: doesn't fix time limitation
def max_product(nums):
    max_prod = float('-inf')
    n = len(nums)
    for i in range(n):
        prod = 1
        for j in range(i, n):
            prod *= nums[j]
            max_prod = max(max_prod, prod)
    return max_prod

# Example usage:
nums = [2, 3, -2, 4]
print(max_product(nums))  # Output: 6
