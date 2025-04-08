

def encode(strs):
    # write your code here
    joined = ''
    extra = ' hisss '
    for word in str:
        joined += word
        joined += extra
    return joined

"""
@param: str: A string
@return: decodes a single string to a list of strings
"""
def decode(s):
    # write your code here
    all_strs = s.split(' hisss ')
    return all_strs
