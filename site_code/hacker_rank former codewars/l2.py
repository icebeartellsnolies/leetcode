# from itertools import combinations
# def is_alternating(lst):
#     if lst[0] == lst[-1]:
#         return False
#     length=len(lst)
#     for i in range(length):
#         next=i+1
#         if next==length:
#             next=0
#         if lst[i] == lst[next]:
#             return False
#     return True
# def cols(colors,k):
#     groups=0
#     combs=list(combinations(colors,k))
#     for c in combs:
#         alternate = is_alternating(c)
#         if alternate:
#             groups+=1
#     return groups

# print(cols([0,1,0,1,0],3))

def alternateGroups(colors, k):
    n = len(colors)
    res = 0
    for i in range(n):
        alt = True
        for j in range(1, k):
            if colors[(i + j) % n] == colors[(i + j - 1) % n]:
                alt = False
                break
        if alt:
            res += 1
    return res

# Example usage
colors = [1,1,0,1]
k = 4
print(alternateGroups(colors, k))  # Output will be the number of alternating groups of size k
colors= [0,1,0,0,1,0,1]
k=6
print(alternateGroups(colors, k))
Input: colors = [0,1,0,1,0], k = 3

# Output: 3
def alternateGroups(colors, k):
    n = len(colors)
    res = 0
    for i in range(n):
        alt = True
        prev_color = colors[i]
        for j in range(1, k):
            curr_color = colors[(i + j) % n]
            if curr_color == prev_color:
                alt = False
                break
            prev_color = curr_color
        if alt:
            res += 1
    return res
colors = [1,1,0,1]
k = 4
print(alternateGroups(colors, k))  # Output will be the number of alternating groups of size k
colors= [0,1,0,0,1,0,1]
k=6
print(alternateGroups(colors, k))
colors = [0,1,0,1,0]
k = 3
print(alternateGroups(colors, k))