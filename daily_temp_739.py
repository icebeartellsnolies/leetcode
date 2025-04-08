# NOTE: brute force solution
# def find_greater(temperatures):
#     pointer2 = 1
#     pointer1 = 0
#     length = len(temperatures)
#     answer = [None]*length
    
#     while pointer1 < length-1:
#         if temperatures[pointer2] > temperatures[pointer1]:
#             answer[pointer1] = 1
#         else:
#             while pointer2 < length:
#                 if temperatures[pointer2] <= temperatures[pointer1]:
#                     pointer2 += 1
#                 else:
#                     break
#             if pointer2 != length:
#                 answer[pointer1] = pointer2-pointer1
#             else:
#                 answer[pointer1] = 0
#         pointer1 += 1
#         pointer2 = pointer1 + 1
#     answer[-1] = 0
#     return answer

# NOTE: stack solution
def find_greater(temperatures):
    answer = [0]*len(temperatures)
    stack = []
    for index, temperature in enumerate(temperatures):
        while stack and temperature > stack[-1][0]:
            stack_temp, stack_index = stack.pop()
            answer[stack_index] = index - stack_index

        stack.append([temperature, index])
    return answer

# print(find_greater([73,74,75,71,69,72,76,73]))
# print(find_greater([30,40,50,60]))
# print(find_greater([30,60,90]))
print(find_greater([89,62,70,58,47,47,46,76,100,70]))