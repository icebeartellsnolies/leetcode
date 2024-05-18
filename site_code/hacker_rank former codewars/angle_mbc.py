import math
ab,bc=map(int,input().split())
ca=(((ab**2)+(bc**2))**0.5)
cm=ca/2
angle_c=math.sin(cm/bc)
angle_c=math.degrees(angle_c)
angle_b=180-(angle_c+90)
print(angle_b)