# from itertools import combinations_with_replacement
# def missing_rolls(rolls, mean, n):
#     dice_faces = range(1, 7)
#     total_len = len(rolls) + n
#     rolls_sum = sum(rolls)
    
#     for candidate in combinations_with_replacement(dice_faces, n):  # Generator, no list creation
#         total = sum(candidate)
#         ans = (rolls_sum + total) / total_len
#         if ans == int(ans) and ans == mean:
#             return list(candidate)  # Convert tuple to list
    
#     return []
def missing_rolls(rolls, mean, n):
    total_sum = mean * (n+len(rolls))
    curr_sum = sum(rolls)
    required_sum = total_sum - curr_sum
    if required_sum < n or required_sum > (n*6):
        return []
    quotient, remainder = divmod(required_sum,n)
    result = [quotient] * n
    for i in range(remainder):
        result[i] += 1
    return result


print(missing_rolls([3,2,4,3],4,2))

print(missing_rolls([1,5,6],3,4))