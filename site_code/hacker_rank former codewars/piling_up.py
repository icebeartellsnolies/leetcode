# import copy
test_cases=int(input())
all=[]
for cases in range(test_cases):
    length=int(input())
    blocks=list(map(int,input().split()))
    all.append(blocks)

# def is_greatest(block,blocks):
#     copy_blocks=copy.deepcopy(blocks)
#     param=False
#     for i in range(len(copy_blocks)):
#         for j in range(i+1,len(copy_blocks)):
#             if copy_blocks[i]<copy_blocks[j]:
#                 copy_blocks[i],copy_blocks[j]=copy_blocks[j],copy_blocks[i]
#     if copy_blocks[0]==block:
#         param=True
#     return param
def is_greatest(block, blocks):
    return block == max(blocks)

for case in range(test_cases):
    block=0
    trues=[]
    while block<(len(all[case])):
        right_remove=is_greatest(all[case][-1],all[case])
        left_remove=is_greatest(all[case][0],all[case])
        if right_remove==True:
            all[case].pop(-1)
            trues.append(right_remove)
        elif left_remove==True:
            all[case].pop(0)
            trues.append(left_remove)
        else:
            trues.append(False)
        if right_remove==False and left_remove==False:
            break
    if False not in trues:
        print('Yes')
    else:
        print('No')


