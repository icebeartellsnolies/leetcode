def remove_comments(source):
    answer = ''
    block_comment = False
    
    splitted = source.split(',')
    for line in splitted:
        line_check = ''
        pointer = 0
        while pointer < (len(line)):
            
            if line[pointer] == '/' and pointer+1 < len(line) and line[pointer+1] == '/' and not block_comment:
                break
            elif line[pointer] == '/' and pointer+1 < len(line) and line[pointer+1] == '*':
                block_comment = True
                pointer += 2
                continue
            elif line[pointer] == '*' and pointer+1 < len(line) and line[pointer+1] == '/':
                block_comment = False
                pointer += 1
            
            elif not block_comment:
                line_check += line[pointer]
            
            pointer += 1
        if len(line) == len(line_check):
            answer += line_check
            answer += ','
            answer = answer.strip()
    answer = answer.strip(',')
    answer = answer.strip()
    if answer[0] != '[':
        answer = '['+answer
    if answer[-1] != ']':
        answer += ']'
    return answer            
 
comm='''["/*Test program */", "int main()", "{ ", "  // variable declaration ", "int a, b, c;",
 "/* This is a test", "   multiline  ", "   comment for ", "   testing */", "a = b + c;", "}"]'''
print(remove_comments(comm))

# a= "ggggggg, asdf, ijhgfx"
# b= a.split(',')
# print(b)