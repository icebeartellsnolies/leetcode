# n: number of pages in the book ; p: page number to turn to
def pageCount(n, p):
    if n%2 != 0:
        return min(p//2, (n-p)//2)
    return min(p//2, (n+1-p)//2)

def pageCount(n, p):
    page_index, last_page_index = p//2, n//2
		
    return min(page_index, last_page_index-page_index)

print(pageCount(7,4))