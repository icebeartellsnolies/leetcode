from collections import defaultdict
def tupleSameProduct(nums):
    products = defaultdict(int)
    for i in range(len(nums)):
        for j in range(i + 1, len(nums)):
            prod = nums[i] * nums[j]
            products[prod] += 1

    combinations = 0
    for prod, count in products.items():
        if count >= 2:
            combinations += (count * (count - 1)) // 2 * 8

    return combinations

# print(tupleSameProduct([2,3,4,6]))
print(tupleSameProduct([1,2,4,5,10]))