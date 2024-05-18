def borrowed(cost,money,quantity):
    sum=0
    i=1
    while i<=quantity:
        sum=sum+(cost*i)
        i=i+1
    to_borrow=0
    if sum>money:
        to_borrow=sum-money
    return to_borrow

x,y,z=map(int, input().split())
print(borrowed(x,y,z))