
def unique(s):
    for i in range(len(s)):
        another=list(s)
        popped=another.pop(i)
        if popped not in another:
            return i
    return -1
print(unique("aabb"))

