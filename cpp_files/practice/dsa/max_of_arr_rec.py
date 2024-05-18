def max_element2(arr, n):
    if (n==1) :
        return arr[0]
    else:
        a=arr[n-1]
        b=max_element2(arr, n-1)
        return max(a,b)

max_element2([1,5,7,2,9],5)
