def content_child(g, s):
    contented = 0
    g = sorted(g)
    s = sorted(s)
    min_len = min(len(g), len(s))
    g_pointer = 0
    s_pointer = 0

    while s_pointer < min_len and g_pointer < min_len:
        if g[g_pointer] <= s[s_pointer]:
            contented += 1
            g_pointer += 1
            s_pointer += 1
        else:
            s_pointer += 1
    return contented

print(content_child([1,2,3],[1,1]))
# print(content_child([10,9,8,7],[5,6,7,8]))
