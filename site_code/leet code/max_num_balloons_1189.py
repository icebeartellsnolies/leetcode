def max_balloons(text):
    hash_map = {}
    total = 0
    for letter in text:
        if letter == 'b' or letter == 'a' or letter == 'l' or letter == 'o' or letter == 'n':
            if letter in hash_map:
                hash_map[letter] += 1
                total += 1
            else:
                hash_map[letter] = 1
                total += 1

    # get the min value of hash map. if letter of min value is l or o then ... else ...
    if len(hash_map) < 5 or total<6:
        return 0
    min_twos = hash_map['o']
    min_ones = hash_map['b']
    # balloon
    # b, a, n
    # l,o
    if  hash_map['a']< min_ones:
        min_ones = hash_map['a']
    elif hash_map['n']< min_ones:
        min_ones = hash_map['n']
    if  hash_map['l']< min_twos:
        min_twos = hash_map['l']
    min_twos = min_twos// 2
    if min_twos < min_ones:
        return min_twos
    else:
        return min_ones
test = '''krhizmmgmcrecekgyljqkldocicziihtgpqwbticmvuyznragqoyrukzopfmjhjjxemsxmrsxuqmnkrzhgvtgdg
tykhcglurvppvcwhrhrjoislonvvglhdciilduvuiebmffaagxerjeewmtcwmhmtwlxtvlbocczlrppmpjbpnifqtlninyzjtm
azxdbzwxthpvrfulvrspycqcghuopjirzoeuqhetnbrcdakilzmklxwudxxhwilasbjjhhfgghogqoofsufysmcqeilaivtmfziu
mjloewbkjvaahsaaggteppqyuoylgpbdwqubaalfwcqrjeycjbbpifjbpigjdnnswocusuprydgrtxuaojeriigwumlovafxnpibjo
pjfqzrwemoinmptxddgcszmfprdrichjeqcvikynzigleaajcysusqasqadjemgnyvmzmbcfrttrzonwafrnedglhpudovigwvpimt
tiketopkvqw'''
print(max_balloons(test))