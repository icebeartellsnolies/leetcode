def get_heavier(limarck,bob):
    limarck_plus=0
    bob_plus=0
    while limarck<bob:
        limarck=limarck*3
        bob=bob*2
        limarck_plus+=1
        bob_plus+=1
    if limarck==bob:
        limarck_plus+=1
    return limarck_plus

x, y = map(int, input().split())

print(get_heavier(x,y))