
def is_valid(val, candies,k):
    count=0
    for i in range(len(candies)):
        if candies[i]//val>=1:
            count+=candies[i]//val
    return count>=k

def maximumCandies(candies,k):
    maximum=sum(candies)//k
    search_space=[i for i in range(1,maximum+1)]
    low=0
    high=len(search_space)-1
    ans=0
    while low<=high:
        mid=(low+high)//2
        if is_valid(search_space[mid], candies,k):
            low=mid+1
            ans=search_space[mid]
        else:
            high=mid-1

    return ans


print(maximumCandies([5,8,6],3))
print(maximumCandies([2,5],11))
print(maximumCandies([4,7,5],4))