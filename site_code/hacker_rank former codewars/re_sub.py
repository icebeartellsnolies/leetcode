# Importing re module
import re

# Given String
s = "I am a && re || "

# Performing Sub() operation
s = re.sub(' && ', ' and ', s)
s = re.sub(r' \|\| ',' or ',s)

# Print Results
print(s)