# fifo: add at the end and remove from front
class Queue:
    def __init__(self, capacity):
        self.capacity = capacity
        self.queue = [None] * capacity
        self.front = self.rear = -1

    def is_empty(self):
        return self.front == self.rear == -1

    def is_full(self):
        return (self.rear + 1) % self.capacity == self.front

    def enqueue(self, item):
        if self.is_full():
            raise IndexError("Enqueue to a full queue")
        if self.is_empty():
            self.front = self.rear = 0
        else:
            self.rear = (self.rear + 1) % self.capacity
        self.queue[self.rear] = item

    def dequeue(self):
        if self.is_empty():
            raise IndexError("Dequeue from an empty queue")
        removed_item = self.queue[self.front]
        if self.front == self.rear:
            self.front = self.rear = -1
        else:
            self.front = (self.front + 1) % self.capacity
        return removed_item

    def size(self):
        if self.is_empty():
            return 0
        # if self.front <= self.rear:
        #     return self.rear - self.front + 1
        # else:
        #     return self.capacity - self.front + self.rear + 1
        return abs(self.front-self.rear)+1

    def display(self):
        if self.is_empty():
            print("Queue is empty")
        else:
            print("Queue:", end=" ")
            if self.front <= self.rear:
                for i in range(self.front, self.rear + 1):
                    print(self.queue[i], end=" ")
            else:
                for i in range(self.front, self.capacity):
                    print(self.queue[i], end=" ")
                for i in range(0, self.rear + 1):
                    print(self.queue[i], end=" ")
            print()


# Example usage
if __name__ == "__main__":
    # Create a queue with a capacity of 5
    queue = Queue(5)

    # Enqueue elements
    queue.enqueue(5)
    queue.dequeue()
    queue.enqueue(10)
    queue.enqueue(15)
    queue.dequeue()
    queue.enqueue(20)

    # Display the queue
    queue.display()
    print(queue.size())
    # # Dequeue an element
    # print("Dequeued:", queue.dequeue())

    # # Display the queue again
    # queue.display()
