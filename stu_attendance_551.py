def check_record(s):
    absents = 0
    lates = 0
    for i in range(len(s)):
        if s[i] == 'A':
            absents += 1
            if absents > 1:
                return False
            lates = 0
        elif s[i] == 'L':
            lates += 1
            if lates > 2:
                return False
        else:
            lates = 0
    return True

print(check_record('PPALLP'))
print(check_record('PPALLL'))