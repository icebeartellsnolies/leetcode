# def myfunc(nam):
#     nam = "Arif Butt"

# a = "Kakamanna"
# print("Before calling: ", a)

# rv = myfunc(a)
# print("After calling: ", a)

# def f1():
#     cc = 1234      # cc is local variable to f1()
#     def f2():
#         cc = 4321  # cc is local variable to f2()
#         print("Inside the f2() function: cc = ", cc)
#     f2()
#     print("Inside the f1() function: cc = ", cc)


# f1()
# c = 1234         # c is a global variable
# def my_function():
#     c = c + 1    # Updating global variable inside function
#     print("Value of variable 'c' inside function: ", c)

# my_function()
# print("Value of variable 'c' outside function: ", c)
# d = 1234
# def my_function():
#     global d   # global keyword does not create a new local variable, rather allows you to access the global var
#     d = d + 1  # Updating global variable inside function
#     print("Value of variable 'd' inside function: ", d)

# my_function()
# print("Value of variable 'd' outside function: ", d)
def f1():
    a = 1234
    def f2():
        a = a + 1
        print("Inside the f2() function: a = ", a)
    f2()
    print("Inside the f1() function: a = ", a)


f1()

# x=5
# print(x, id(x))
# def number():
#     x = 3
#     print(x, id(x))
#     def f1():
#         nonlocal x
#         print(x, id(x))
#         x = x * 5
#         print(x, id(x))
#     f1()
# def numb():
#     global x
#     x = x * 5
#     print(x, id(x))
# number()
# numb()    
# print(x, id(x))