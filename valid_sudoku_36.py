def is_valid(sudoku):
    #first check
    first_check=False
    row_check=False
    block_check=False
    col_check=False
    finale_1=[]
    for i in range(len(sudoku)):
        only_ints=[]
        first_checks=[]
        for j in range(len(sudoku[i])):
            only_int=[]
            if ord(sudoku[i][j])>=48 and ord(sudoku[i][j])<58:
                only_int.append(sudoku[i][j])
                only_ints.append(sudoku[i][j])
                count=0
                for k in range(len(sudoku[i])):
                    if only_int[0]==sudoku[i][k]:
                        count+=1
                if count==1:
                    first_check=True
                    first_checks.append(first_check)

        if len(only_ints)==len(first_checks):
            finale_1.append(True)
        else:
            finale_1.append(False)
    if False not in finale_1:
        row_check= True
    else:
        row_check= False
    #second check
    if row_check==True:
        sec_check=False
        finale_2=[]
        for i in range(len(sudoku)):
            only_ints=[]
            sec_checks=[]
            for j in range(len(sudoku[i])):
                only_int=[]
                if ord(sudoku[j][i])>=48 and ord(sudoku[j][i])<58:
                    only_int.append(sudoku[j][i])
                    only_ints.append(sudoku[j][i])
                    count=0
                    for k in range(len(sudoku[i])):
                        if only_int[0]==sudoku[k][i]:
                            count+=1
                    if count==1:
                        sec_check=True
                        sec_checks.append(sec_check)

            if len(only_ints)==len(sec_checks):
                finale_2.append(True)
            else:
                finale_2.append(False)
        if False not in finale_2:
            col_check= True
        else:
            col_check= False
    #third check
    if col_check==True and row_check==True:
        third_check=False
        
        
        finale_3=[]
        checker=0
        while checker <(9):
            third_checks=[]
            i=checker//3
            if checker==3 or checker==4 or checker==5:
                i=3
            if checker==6 or checker==7 or checker==8:
                i=6 
            only_ints=[]
            that_i=i+3
            while i<that_i:
                j=checker*3
                
                if j >6:
                    j=0
                that_j=j+3
                while j<that_j:
                    only_int=[]
                    if ord(sudoku[i][j])>=48 and ord(sudoku[i][j])<58:
                        only_int.append(sudoku[i][j])
                        only_ints.append(sudoku[i][j])
                    
                    j=j+1
                i=i+1
            for i in range(len(only_ints)):
                for j in range(len(only_ints)):
                    if i!=j:
                        if only_ints[i]==only_ints[j]:
                            third_check=False
                            third_checks.append(third_check)
                        else:
                            third_check=True
                            third_checks.append(third_check)
            if False not in third_checks:
                finale_3.append(True)
            else:
                finale_3.append(False)
            checker=checker+1
        if False not in finale_3:
            block_check=True
    if block_check==True and row_check==True and col_check==True:
        return True
    else:
        return False


sod=[["8","3",".",".","7",".",".",".","."]
,["6",".",".","1","9","5",".",".","."]
,[".","9","8",".",".",".",".","6","."]
,["8",".",".",".","6",".",".",".","3"]
,["4",".",".","8",".","3",".",".","1"]
,["7",".",".",".","2",".",".",".","6"]
,[".","6",".",".",".",".","2","8","."]
,[".",".",".","4","1","9",".",".","5"]
,[".",".",".",".","8",".",".","7","9"]]
print(is_valid(sod))