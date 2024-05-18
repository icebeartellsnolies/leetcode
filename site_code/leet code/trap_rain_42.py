def trapped_water(blocks):
    # sec_largest_exists=False
    largest=blocks[0]
    for i in range(len(blocks)):
        if blocks[i]>largest:
            largest=blocks[i]
    if blocks[-1]==largest:
        # sec_largest_exists=True
        sorted_blocks=blocks
        for i in range(len(blocks)):
            for j in range(i+1,len(blocks)):
                if sorted_blocks[i]<sorted_blocks[j]:
                    sorted_blocks[i],sorted_blocks[j]=sorted_blocks[j],sorted_blocks[i]
        for i in range(len(sorted_blocks)):
            if sorted_blocks[i]<sorted_blocks[0]:
                second_largest=sorted_blocks[i]
                break
        index=0
        for i in range(len(blocks)):
            if blocks[i]==second_largest:
                index=i
                break
    else:
        for i in range(len(blocks)):
            if blocks[i]==largest:
                index=i
    
    sum=0
    for i in range(index,len(blocks)):
        sum+=blocks[index]-blocks[i]
    return sum 
a=[0,1,0,2,1,0,1,3,2,1,2,1]
print(trapped_water(a))
