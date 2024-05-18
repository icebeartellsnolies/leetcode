# def hackerland(x,k):
#     x.sort()    
#     i=0
#     reference=x[1]
#     count=1
#     while i<len(x):

#         if abs(reference-x[i])>k :
#             reference=x[i]
#             count+=1
#             i+=1
#         else:
#             i+=2
#             if x[i]==x[-1]:
#                 break
#             else:
#                 while x[i]<=k+reference and i<len(x):
#                     i+=1
#                 i-=1
#                 if i+2<len(x):
#                     reference=x[i+1]
#                     i+=1
#                     count+=1
#     return count

# print(hackerland([1,2,3,5,9],1))
# # [2,4,5,6,7,9,11,12],2
# # [1,2,3,5,9],1

# algorithm
# first, find out current position (start)
# second, find the center (start + k, or approximate)
# third, find how far our range extends (center + k, or approximate), and remove anything up to that point in the array
# test = [1, 4, 5, 9, 11], k = 2, solution = [1, 5, 11]
def hackerlandRadioTransmitters(x, k):
    array = x # just for readability
    array.sort() # array not guaranteed to be sorted
    results = []
    while array:
        start = array[0]
        center = start + k
        while (center not in array):
            center -= 1 # take a step back
        results.append(center)
        end = center + k
        while array and array[0] <= end:
            array.pop(0)
    print("results: ", results)
    return len(results)

print(hackerlandRadioTransmitters([2,4,5,6,7,9,11,12],2))