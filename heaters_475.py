def find_extremes(house, heaters):
    jh=jl=-1
    low =0
    high=len(heaters)-1
    while low<=high:
        mid = low + (high - low) // 2
        if heaters[mid]==house:
            return heaters[mid],heaters[mid]
        elif heaters[mid]>house:
            jh=heaters[mid]
            high=mid-1
        else:
            jl=heaters[mid]
            low=mid+1
    return jl,jh

def findRadius(houses, heaters):
    houses.sort()
    heaters.sort()
    radius=0
    for house in houses:
        l,h=find_extremes(house,heaters)
        dl=abs(house-l)
        dh=abs(house-h)
        if l==-1:
            dl=float("inf")
        if h==-1:
            dh=float("inf")

        min_d=min(dh,dl)
        radius=max(min_d,radius)
    return radius

print(findRadius([1,2,3],[1,2,3]))