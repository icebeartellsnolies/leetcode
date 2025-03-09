class StackArray:
    def __init__(self, capacity):
        self.capacity = capacity
        self.stack = [None] * capacity
        self.top = -1

    def is_empty(self):
        return self.top == -1

    def is_full(self):
        return self.top == self.capacity - 1

    def push(self, item):
        if self.is_full():
            raise IndexError("Push to a full stack")
        self.top += 1
        self.stack[self.top] = item

    def pop(self):
        if self.is_empty():
            raise IndexError("Pop from an empty stack")
        item = self.stack[self.top]
        self.top -= 1
        return item

    def peek(self):
        if self.is_empty():
            raise IndexError("Peek from an empty stack")
        return self.stack[self.top]

    def size(self):
        return self.top + 1

    def display(self):
        if self.is_empty():
            print("Stack is empty")
        else:
            print("Stack:", end=" ")
            for i in range(self.top, -1, -1):
                print(self.stack[i], end=" ")
            print()


# Example usage
if __name__ == "__main__":
    # Create a stack with a capacity of 5
    stack = StackArray(5)

    # Push elements onto the stack
    stack.push(5)
    stack.push(10)
    stack.push(15)
    stack.push(20)

    # Display the stack
    stack.display()

    # Pop an element
    print("Popped:", stack.pop())

    # Display the stack again
    stack.display()
