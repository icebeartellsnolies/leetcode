def reverse(s):
    splitted=s.split()
    splitted.reverse()
    reverse_str=' '.join(splitted)
    return reverse_str
print(reverse('the sky is blue'))
