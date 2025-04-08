from collections import defaultdict
def grouping(strs):
    hash_map = defaultdict(list)
    for word in strs:
        sorted_word = ''.join(sorted(word))
        hash_map[sorted_word].append(word)
    return list(hash_map.values())


# print(grouping(["eat","tea","tan","ate","nat","bat"]))
# NOTE: Neetcode's
# def grouping(strs):
#     res = defaultdict(list)
#     for s in strs:
#         count = [0]*26
#         for c in s:
#             count[ord(c) - ord('a')] += 1
#         to_add = tuple(count)
#         res[to_add].append(s)
#     return res.values()

print(grouping(['a']))
print(grouping(["eat","tea","tan","ate","nat","bat"] ))