class Node:
    def __init__(self, data=None):
        self.data = data
        self.next = None

class Queue:
    def __init__(self):
        self.front = None
        self.rear = None

    def is_empty(self):
        return self.front is None

    def enqueue(self, item):
        new_node = Node(item)
        if self.rear is None:
            self.front = self.rear = new_node
            return
        self.rear.next = new_node
        self.rear = new_node

    def dequeue(self):
        if self.is_empty():
            raise IndexError("Dequeue from an empty queue")
        removed_item = self.front.data
        self.front = self.front.next
        if self.front is None:
            self.rear = None
        return removed_item

    def size(self):
        count = 0
        current = self.front
        while current:
            count += 1
            current = current.next
        return count
    
    def __str__(self):
        if self.is_empty():
            return "Queue is empty"
        current = self.front
        result = []
        while current:
            result.append(current.data)
            current = current.next
        return " -> ".join(map(str, result))
 
# Example usage
my_queue = Queue()

my_queue.enqueue(1)
my_queue.enqueue(2)
my_queue.enqueue(3)
my_queue.enqueue(3)
my_queue.enqueue(3)
my_queue.enqueue(3)

print(my_queue)
print("Queue size:", my_queue.size())

print("Dequeue:", my_queue.dequeue())
print("Dequeue:", my_queue.dequeue())

print("Is the queue empty?", my_queue.is_empty())
