# def minimum_loss(price):
#     differences=[]
#     for first in range(len(price)):
#         for second in range(first+1, len(price)):
#             diff = price[second] - price[first]
#             if diff < 0:
#                 differences.append(diff)

#     return abs(max(differences))

# print(minimum_loss([5,10,3]))


# NOTE:CHATGPT
# def minimum_loss(price):
#     # Create a list of (price, index) tuples
#     price_index = list(enumerate(price))
#     # Sort the list by price
#     price_index.sort(key=lambda x: x[1])

#     min_loss = float('inf')
#     for i in range(1, len(price)):
#         diff = price_index[i][1] - price_index[i-1][1]
#         if diff < min_loss and price_index[i][0] < price_index[i-1][0]:
#             min_loss = diff
    
#     return min_loss

# # Example usage
# price = [20, 15, 8, 2, 12]
# print(minimum_loss(price))  # Output should be 3

# NOTE:Amir's approach; not right
def minim_loss(price):
    min_los=price[0]
    for i in range(1,len(price)):
        if min_los + price[i]<0:
            min_los = min_los
        else:
            min_los += price[i]
    return min_los

print(sum([20, 7, 8, 2, 1]))
print(minim_loss([20, 7, 8, 2, 1]))
print(minim_loss([6,8,9,0,6]))
print(sum([6,8,-9,0,-6]))
print(minim_loss([6,8,-9,0,-6]))