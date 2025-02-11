def h_index(citations):
    citations.sort()
    end = len(citations)
    pointer = 0
    while pointer < end:
        if (end - pointer) <= citations[pointer]:
            return end - pointer
        pointer += 1
    return 0
print(h_index([3,0,6,1,5]))
print(h_index([1,3,1]))