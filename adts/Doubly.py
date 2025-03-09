class Node:
    def _init_(self, val):
        self.info = val
        self.next = None
        self.prev = None

class Doubly:
    def _init_(self):
        self.head = self.tail = None
    
    def insert_at_head(self, val):
        new_node = Node(val)
        if self.head == None:
            self.head = self.tail = new_node
            return
        new_node.next = self.head
        self.head.prev = new_node
        self.head = new_node
    
    def insert_at_tail(self, val):
        new_node = Node(val)
        if self.head == None:
            self.head = self.tail = new_node
            return
        self.tail.next = new_node
        new_node.prev = self.tail
        self.tail = new_node
        
    def insert_after(self, key, val):
        new_node = Node(val)
        if self.head is None:
            self.head = self.tail = new_node
            return
        temp = self.head
        while temp:
            if temp.info == key:
                new_node.next = temp.next
                temp.next.prev = new_node
                temp.next = new_node
                new_node.prev = temp
            temp = temp.next
        
    def insert_before(self, key, val):
        new_node = Node(val)
        if self.head == None:
            self.head = self.tail = new_node
            return
        temp = self.head
        while temp:
            if temp.info == key:
                temp.prev.next = new_node
                new_node.prev = temp.prev
                new_node.next = temp
                temp.prev = new_node
            temp = temp.next
    
    def remove_from_head(self):
        if self.head is None:
            return
        self.head = self.head.next
        self.head.prev = None
        
    def remove_from_tail(self):
        if self.head is None:
            return
        temp = self.tail.prev
        temp.next = None
        self.tail = temp
        
    def remove_after(self, key):
        if self.head is None:
            return
        temp = self.head
        while temp:
            if temp.info == key:
                temp.next = temp.next.next
                temp.next.prev = temp
            temp = temp.next
            
    def remove_before(self, key):
        if self.head is None:
            return
        temp = self.head
        while temp:
            if temp.info == key:
                temp.prev = temp.prev.prev
                temp.prev.next = temp
            temp = temp.next
            
    def display(self):
        temp = self.head
        while temp:
            print(temp.info, end = ' ')
            temp = temp.next
    
    def rev_display(self):
        temp = self.tail
        while temp:
            print(temp.info, end = ' ')
            temp = temp.prev

def main():
    s = Doubly()
    s.insert_at_head(3)
    s.insert_at_head(1)
    s.insert_at_tail(5)
    s.insert_after(1, 2)
    s.insert_before(5, 4)
    #s.remove_from_head()
    #s.remove_after(2)
    s.remove_before(5)
    s.display()
    print()
    #s.remove_from_tail()
    
    s.rev_display()

main()