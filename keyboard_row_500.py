def find_words(words):
    row1 = {'q','w','e','r','t','y','u','i','o','p'}
    row2 = {'a','s','d','f','g','h','j','k','l'}
    row3 = {'z','x','c','v','b','n','m'}
    final_arr = []
    
    for word in words:
        row = None
        broken = False
        for letter in word :
            if row == None:
                if letter  in row1:
                    row = 1
                elif letter  in row2:
                    row = 2
                else:
                    row = 3
            else:
                if letter  in row1:
                    new_row = 1
                elif letter  in row2:
                    new_row = 2
                else:
                    new_row = 3
                if new_row!=row:
                    broken = True
                    break

        if not broken:
            final_arr.append(word)
    return final_arr
print(find_words(["Hello","Alaska","Dad","Peace"]))
        
