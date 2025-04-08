def last_word_len(words):
    words=words.strip()
    total_words=words.split(' ')
    last_word=total_words[-1]
    desired_len=len(last_word)
    return desired_len

print(last_word_len("   fly me   to   the moon  "))