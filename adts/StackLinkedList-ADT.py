class Node:
    def __init__(self, val) -> None:
        self.info = val
        self.next = None

class StackedLinkedList:
    def __init__(self):
        self.head = None

    def push(self,data):
        if self.head is None:
            self.head = Node(data)
            return
        new_node = Node(data)
        new_node.next = self.head
        self.head = new_node

    def pop(self):
        if self.head is None:
            return 'Error. List is empty.'
        element = self.head.info
        self.head = self.head.next
        return element
    
    def peek(self):
        if self.isEmpty():
            return 'Empty. Stack Underflow.'
        return self.head.info
    
    def isEmpty(self):
        if self.head == None:  #return self.head is none
            return True
        return False
    
    def size(self):
        count = 0
        while self.head is not None:
            count +=1
            self.head = self.head.next
        else:
            return f'size of stack is {count}'

    def __str__(self):
        current = self.head
        result = []

        while current is not None:
            result.append(current.info)
            current = current.next

        if not result:
            return 'Stack is empty.'
        else:
            return ' -> '.join(map(str, result[::-1]))
        

def main():
    stack = StackedLinkedList()

    # Push some elements onto the stack
    stack.push(5)
    stack.push(10)
    stack.push(15)
    stack.push(20)

    print("Stack after pushing elements:")
    print(stack)

    # Pop elements from the stack
    print("\nPopping elements:")
    print(stack.pop())
    print(stack.pop())
    print(stack.pop())

    print("\nStack after popping elements:")
    print(stack)

    # Peek at the top element
    print("\nPeeking at the top element:")
    print(stack.peek())

    # Get the size of the stack
    print("\nSize of the stack:")
    print(stack.size())

if __name__ == "__main__":
    main()
  