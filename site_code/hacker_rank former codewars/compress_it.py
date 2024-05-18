# from itertools import groupby

# def encode(input_str):
#     grouped_digits = [(len(list(g)), int(k)) for k, g in groupby(input_str)]
#     print( grouped_digits)

# def decode(grouped_digits):
#     decoded_str = ''.join(str(count) + str(digit) for count, digit in grouped_digits)
#     return decoded_str

# input_str = "1222311"

# # Encode the input string
# encoded_result = encode(input_str)

# # Print the result in the specified format
# formatted_result = ' '.join(f'({count},{digit})' for count, digit in encoded_result)
# print(formatted_result)

from itertools import groupby

def compress_string(string):
  """Compresses a string by grouping consecutive occurrences of characters and 
  outputting the count and character as a tuple.

  Args:
      string: The string to compress.

  Returns:
      A list of tuples, where each tuple represents a group of consecutive characters
      (count, character).
  """
  return [(len(list(group)), int(key)) for key, group in groupby(string)]

# Get input string
input_string = input("Enter a string: ")

# Compress and print the string
compressed_string = compress_string(input_string)
print(compressed_string)

