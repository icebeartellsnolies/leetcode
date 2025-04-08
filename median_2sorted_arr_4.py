def median_of_two(arr1,arr2):
    merge=arr1+arr2
    sorted_arr=sort(merge)
    if len(sorted_arr)%2==0:
        index2=int(len(sorted_arr)/2)
        index1=index2-1
        median=(sorted_arr[index1]+sorted_arr[index2])/2
        
    else:
        median_index=len(sorted_arr)//2
        median=sorted_arr[median_index]
    return median

def sort(arr):
    for i in range(len(arr)):
        j=i+1
        while j<len(arr):
            if arr[i]>arr[j]:
                arr[i],arr[j]=arr[j],arr[i]
            j=j+1
    return arr

ray1=[1,2]
ray2=[3,4]
print(median_of_two(ray1,ray2))