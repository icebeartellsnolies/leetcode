def hashed_str(s,k):
    # mapping = {chr(i): i - 97 for i in range(97, 123)}
    splits = len(s)//k
    # splitted = []
    # pointer1 = 0
    # pointer2 = k
    sum = 0
    to_return = ''
    for i, char in enumerate(s):
        sum += ord(char)-97  # Add the current character to the current piece
        
        # If the current piece is of the desired size, add it to the pieces list
        if (i) % k == 0:
            cal = 97 - sum
            to_return += chr(cal)
            sum = 0
    return to_return

print(hashed_str('abcd',2))

print(hashed_str('mxz', 3))
# print(ord('m'))
