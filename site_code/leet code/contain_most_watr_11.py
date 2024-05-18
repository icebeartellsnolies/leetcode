def capacity(heights):
    l, r = 0, len(heights)-1
    max_area = 0
    while l < r:
        length = min(heights[l],heights[r])
        width = r - l
        area = length*width
        if area > max_area:
            max_area = area
        if heights[l] < heights[r]:
            l += 1
        else:
            r -= 1
    return max_area

# print(capacity([1,8,6,2,5,4,8,3,7]))
# print(capacity([1,1]))
print(capacity([2,3,4,5,18,17,6]))