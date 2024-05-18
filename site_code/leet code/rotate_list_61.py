def rotate(head,k):
    for change in range(k):
        popped=head.pop(-1)
        head.insert(0,popped)
    return head
print(rotate([0,1,2],4))