intuition ='''the if statement finds the local minima and the else statement finds the max diff by finding 
local maximia'''
def max_profit(prices):
    l = 0
    r = 1
    max_prof = 0
    while r < len(prices):
        if prices[l] > prices[r]:
            l = r
        else:
            diff = prices[r] - prices[l]
            if diff > max_prof:
                max_prof = diff
        r += 1
    return max_prof

print(max_profit([7,1,5,3,6,4]))

# def max_profit(prices):
#     l, r = 0, 1
#     max_p = 0
#     while r < len(prices):
#         if prices[l] < prices[r]:
#             profit = prices[r] - prices[l]
#             max_p = max(profit, max_p)
#         else:
#             l = r
#         r += 1
#     return max_p

# print(max([7,1,5,3,6,4]))
