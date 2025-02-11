def count_stones(jewels, stones):
    count = 0
    jewels_set = set(jewels)
    for jewel in jewels_set:
        count+=stones.count(jewel)
    return count

print(count_stones("z","ZZ"))