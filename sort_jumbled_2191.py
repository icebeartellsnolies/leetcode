def sequenced(a,b):
    combined=list(zip(a,b))
    combined = sorted(combined ,key=lambda x:x[1])
    a_sorted, b_sorted = zip(*combined)
    return list(a_sorted)

def sort_jumble(mapping, nums):
    updated = []
    for number in nums:
        str_num=str(number)
        new_num=''
        for digit in str_num:
            to_replace = int(digit)
            replacement = mapping[to_replace]
            new_num += str(replacement)
        
        updated.append(int(new_num))
    to_return = sequenced(nums, updated)
    return to_return

# print(sort_jumble([8,9,4,0,2,1,3,5,7,6],[991,338,38]))
# print(sort_jumble([0,1,2,3,4,5,6,7,8,9],[789,456,123]))
print(sort_jumble([5,6,8,7,4,0,3,1,9,2],[7686,97012948,84234023,2212638,99]))