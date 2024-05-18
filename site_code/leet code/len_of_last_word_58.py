def len_last(s):
    s=s.strip()
    lst_s=s.split(' ')
    return len(lst_s[-1])
print(len_last("   fly me   to   the moon  "))