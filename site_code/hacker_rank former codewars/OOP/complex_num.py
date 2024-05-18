
import math
class Complex(object):
    
    def __init__(self, real=0, imaginary=0):
        self.real=real
        self.img=imaginary

    def __add__(self, no):
        added=complex(self.real,self.img)+complex(no.real,no.img)
        added=str(added)
        added=added[1:-1]
        return added
    
    def __sub__(self, no):
        sub=complex(self.real,self.img)-complex(no.real,no.img)
        sub=str(sub)
        sub=sub[1:-1]
        return sub
    def __mul__(self, no):
        multi=complex(self.real,self.img)*complex(no.real,no.img)
        multi=str(multi)
        multi=multi[1:-1]
        return multi
    def __truediv__(self, no):
        divided=complex(self.real,self.img)/complex(no.real,no.img)
        divided=str(divided)
        divided=divided[1:-1]
        return divided
    def mod(self):
        moded=complex(self.real,self.img)
        moded=abs(moded)
        return f'{moded}+0.00i'

def main():
    a=Complex(2,1)
    b=Complex(5,6)
    print(a-b)
    print(a+b)
    print(a/b)
    print(a.mod())
main()

