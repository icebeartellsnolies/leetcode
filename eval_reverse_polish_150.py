import operator
def evaluate_post_fix(tokens):
    operators ={'*':operator.mul, '+':operator.add, '-':operator.sub, '/':operator.truediv}
    if len(tokens) == 1:
        return int(tokens[0])
    numbers = []
    for token in tokens:
        if token not in operators:
            numbers.append(int(token))
        else:
            operation = operators[token]
            if operation == operator.truediv and abs(numbers[-2])<abs(numbers[-1]):
                result = 0
            else:
                result = int(operation(numbers[-2], numbers[-1]))
            numbers.pop(-1)
            numbers.pop(-1)
            numbers.append(result)
    return result
# print(evaluate_post_fix(["2","1","+","3","*"]))
# print(evaluate_post_fix(["4","13","5","/","+"]))
# print(evaluate_post_fix(["10","6","9","3","+","-11","*","/","*","17","+","5","+"]))
# print(evaluate_post_fix(['18']))
# print(evaluate_post_fix(["3","11","+","5","-"]))
# print(evaluate_post_fix(["3","11","5","+","-"]))
# print(evaluate_post_fix(["4","-2","/","2","-3","-","-"]))
print(evaluate_post_fix(["-78","-33","196","+","-19","-","115","+","-","-99","/","-18","8","*","-86",
                         "-","-","16","/","26","-14","-","-","47","-","101","-","163","*","143","-","0","-",
                         "171","+","120","*","-60","+","156","/","173","/","-24","11","+","21","/","*","44",
                         "*","180","70","-40","-","*","86","132","-84","+","*","-","38","/","/","21","28","/",
                         "+","83","/","-31","156","-","+","28","/","95","-","120","+","8","*","90","-","-94",
                         "*","-73","/","-62","/","93","*","196","-","-59","+","187","-","143","/","-79","-89",
                         "+","-"]))