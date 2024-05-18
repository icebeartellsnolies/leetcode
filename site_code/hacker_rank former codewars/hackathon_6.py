# def to_find(query):
#     sorted_q= sorted(query)
#     i=1
#     result=[]
#     while len(result) <= sorted_q[-1]:
#         bin_form = bin(i)
#         num_of_ones=0
#         for digit in range(len(str(bin_form))):
#             if str(bin_form)[digit] == '1':
#                 num_of_ones += 1
#         for times in range(num_of_ones):
#             result.append(i)
#         i += 1
#     final=[]
#     for p in query:
#         final.append(result[p])
#     return final

# print(to_find([2,3,6]))
# print(to_find([5,0,5]))
# print(to_find([4,10]))

# NOTE:CHATGPT
def to_find(query):
    max_q = max(query)
    result = []
    i = 1
    while len(result) <= max_q:
        num_of_ones = bin(i).count('1')
        result.extend([i] * num_of_ones)
        i += 1
    return [result[p] for p in query]

print(to_find([2,3,6]))
print(to_find([5,0,5]))
print(to_find([4,10]))