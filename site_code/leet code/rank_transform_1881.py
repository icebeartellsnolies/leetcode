def transform_rank(arr):
    set_arr = set(arr)
    sorted_arr = sorted(list(set_arr))
    value_dict = {}
    for i in range(len(sorted_arr)):
        value_dict[sorted_arr[i]] = i+1
    for i in range(len(sorted_arr)):
        arr[i] = value_dict[sorted_arr[i]]
    return arr

print(transform_rank([100,100,100]))
# print(transform_rank([40,10,20,30,40]))