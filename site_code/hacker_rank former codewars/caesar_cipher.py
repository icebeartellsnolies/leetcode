def cipher(s,k):
   k=k%26
   outcome_s=''
   for letter in s:
      if (ord(letter)>=97 and ord(letter)<=122) or (ord(letter)>=65 and ord(letter)<=90):
         new_word=chr(ord(letter) + k)
         if (letter.isupper() and new_word.isupper()) or (letter.islower() and new_word.islower()):
            outcome_s+=new_word
         else:
             new_ord=ord(letter) - 26 +k
             outcome_s+=chr(new_ord)
      else:
         outcome_s+=letter
   return outcome_s
   
# print(cipher(f'There\'s_a_starman_waiting_in_the_sky',3))
# print(cipher('middle-Outz',2))
# print(cipher('www.abc.xy',87))
# print(ord('j')-ord('a'))
# print(87%26)
print(cipher('6DWV95HzxTCHP85dvv3N{Y}2crzt1aO8j6g2zSDvFUiJj6{X}WDl{Z}vNNr',87))
# output=      '6MFE95QigCLQY85mee3W{b}2laic1jX8s6p2iBMeODrSs6{a}FMu{c}eWWa'
# needed_out=  '6MFE95QigCLQY85mee3W{H}2laic1jX8s6p2iBMeODrSs6{G}FMu{I}eWWa'
print('.'.isupper())