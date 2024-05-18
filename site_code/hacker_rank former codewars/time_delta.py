#!/bin/python3

import math
import os
import random
import re
import sys
from datetime import datetime
# Complete the time_delta function below.
def time_delta(t1, t2):
    date_format = "%a %d %b %Y %H:%M:%S %z"
    date1 = datetime.strptime(t1, date_format)
    date2 = datetime.strptime(t2, date_format)

# Perform addition and subtraction operations
    time_difference = date1 - date2


# Print the results
    return (str(int(time_difference.total_seconds())))

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    t = int(input())

    for t_itr in range(t):
        t1 = input()

        t2 = input()

        delta = time_delta(t1, t2)

        fptr.write(delta + '\n')

    fptr.close()
