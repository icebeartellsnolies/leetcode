def swap_pairs(head):
    if len(head)!=0:
        if len(head)%2==0:
            i=0
            while i<len(head):
                head[i],head[i+1]=head[i+1],head[i]
                i+=2
    
    return head
print(swap_pairs([1]))