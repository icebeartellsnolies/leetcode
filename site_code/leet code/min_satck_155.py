class MinStack:
    
    def __init__(self):
        self.stack = []
        
    def push(self, val: int) -> None:
        if len(self.stack)==0:
            self.min_val = val
        else:
            if val < self.min_val:
                self.min_val = val
        self.stack.insert(0,val)

    def pop(self) -> None:
        self.stack.pop(0)

    def top(self) -> int:
        return self.stack[0]

    def getMin(self) -> int:
        return self.min_val

a=MinStack()
# a.push(2)
# a.push(8)
a.push(-2)
a.push(0)
a.push(-3)
print(a.getMin())