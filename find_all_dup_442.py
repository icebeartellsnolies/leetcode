from collections import Counter
def find_duplicates(nums):
    count = dict(Counter(nums))
    duplicates = []
    for key,val in count.items():
        if val == 2:
            duplicates.append(key)
    
    return duplicates

print(find_duplicates([4,3,2,7,8,2,3,1]))