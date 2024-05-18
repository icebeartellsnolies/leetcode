def has_cycle(head):
    cur=head
    a_cur=head.next
    while a_cur.next!=None and cur.next!=None:
        if cur.next!=a_cur:
            return False
    return True
