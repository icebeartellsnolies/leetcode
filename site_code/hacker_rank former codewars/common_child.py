def is_child_string(parent, child):

  parent_char_set = set(parent)
  if not all(char in parent_char_set for char in child):
    return False

  i, j = 0, 0
  while i < len(parent) and j < len(child):
    if parent[i] == child[j]:
      i += 1
      j += 1
    else:
      i += 1
  return j == len(child)

def common_child(s1,s2):
  commons=[]
  combinations=[]
  for i in s1:
      if i in s2:
          commons.append(i)

  for i in range(len(commons)):
      for j in range(i, len(commons)):
          substring = ''.join(commons[i:j+1])
          is_child=is_child_string(s2,substring)
          if is_child==True:
              combinations.append(substring)
  if len(combinations)==0:
     return 0
  to_return=combinations[0]
  for i in range(len(combinations)):
     if len(to_return)<len(combinations[i]):
        to_return=combinations[i]
  return len(to_return)
print(common_child('AA','BB'))
