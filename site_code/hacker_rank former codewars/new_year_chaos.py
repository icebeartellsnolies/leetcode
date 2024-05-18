def min_bribes(q):
    bribes = 0
    i=1
    printed=False
    while i<(len(q)+1):
        if q[i-1] != i:
            new_bribe = (q[i-1] - i)
            if new_bribe > 2:
                print('too chaotic')
                printed=True
                break
            bribes +=new_bribe 
            index = q[i-1] -1
            old_val = q[index]
            q[index] = q[i-1]
            q[i-1] = old_val
        i+=1
    if printed == False:
        print(bribes)
min_bribes([2,1,5,3,4])
