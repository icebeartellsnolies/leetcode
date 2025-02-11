def is_valid(s):
    stack = []
    close_to_open = {
        ')':'(',
        ']':'[',
        '}':'{'
    }
    '''
    whenever we encounter a closing bracket, we check whether its opening bracket has just been added.
    if yes then we remove that opening bracket
    ps. we never add a closing bracket to the stack
    '''
    for char in s:
        if char in close_to_open:
            if stack and stack[-1] == close_to_open[char]:
                stack.pop()
            else:
                return False
        else:
            stack.append(char)
    if  not stack:
        return True
    else:
        return False

print(is_valid('{[]}'))