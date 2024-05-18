#### Task 01: Sum of the First N Natural Numbers

def sum_natural(n):
    if n == 1:
        return 1
    return n + sum_natural(n - 1)


#### Task 02: GCD of Two Positive Numbers

def gcd(a, b):
    if b == 0:
        return a
    return gcd(b, a % b)


#### Task 03: Convert Decimal to Binary

def decimal_to_binary(n):
    if n == 0:
        return ""
    a=n//2
    b=n%2
    return decimal_to_binary(a) + str(b)
# print(decimal_to_binary(3))

#### Task 04: Check if a Number is Prime

def is_prime(n, i=2):
    if n <= 2:
        return n == 2
    if n % i == 0:
        return False
    if i * i > n:
        return True
    return is_prime(n, i + 1)
# print(is_prime(5))

#### Task 05: Check if a Number is a Perfect Square

def is_perfect_square(n, i=1):
    if i * i == n:
        return True
    if i * i > n:
        return False
    return is_perfect_square(n, i + 1)


#### Task 06: Calculate Power (x^n)

def power(x, n):
    if n == 0:
        return 1
    return x * power(x, n - 1)


#### Task 07: Fibonacci Series

def fibonacci(n):
    if n <= 1:
        return n
    return fibonacci(n - 1) + fibonacci(n - 2)


#### Task 08: Pattern with N lines (* increasing)

def print_pattern1(n, i=1):
    if i > n:
        return
    print("* " * i)
    print_pattern1(n, i + 1)


#### Task 09: Centered Pattern with N lines (* increasing)

def print_pattern2(n, i=1):
    if i > n:
        return
    print(" " * (n - i) + "* " * i)
    print_pattern2(n, i + 1)


#### Task 10: Alphabet Pattern

def print_pattern3(n, i=1):
    if i > n:
        return
    print((chr(64 + i) + " ") * i)
    print_pattern3(n, i + 1)




### Array Problems

#### Task 01: Count Occurrences of an Element in an Array

def count_occurrences(arr, x, n=0):
    if n == len(arr):
        return 0
    return (1 if arr[n] == x else 0) + count_occurrences(arr, x, n + 1)


#### Task 02: Binary Search Algorithm

def binary_search(arr, target, left, right):
    if left > right:
        return -1
    mid = (left + right) // 2
    if arr[mid] == target:
        return mid
    elif arr[mid] < target:
        return binary_search(arr, target, mid + 1, right)
    else:
        return binary_search(arr, target, left, mid - 1)


#### Task 03: Partition Array for Equal Left-Right Sum
def partition_equal_sum(arr, left_sum=0, index=0):
    if index == len(arr):
        return False
    right_sum = sum(arr[index + 1:])
    if left_sum == right_sum:
        return True
    return partition_equal_sum(arr, left_sum + arr[index], index + 1)


#### Task 04: Partition Array for Equal Number of Even Integers
def partition_equal_even(arr, index=0, left_even=0):
    if index == len(arr):
        return False
    if left_even == (len(arr) - left_even):
        return True
    left_even += 1 if arr[index] % 2 == 0 else 0
    return partition_equal_even(arr, index + 1, left_even)


#### Task 05: Check if Any Three Elements Sum to 100

def three_sum_to_100(arr, index=0, count=0, current_sum=0):
    if count == 3:
        return current_sum == 100
    if index >= len(arr):
        return False
    return three_sum_to_100(arr, index + 1, count + 1, current_sum + arr[index]) or three_sum_to_100(arr, index + 1, count, current_sum)


#### Task 06: Check if Any K Elements Sum to 100

def k_sum_to_100(arr, k, index=0, count=0, current_sum=0):
    if count == k:
        return current_sum == 100
    if index >= len(arr):
        return False
    return k_sum_to_100(arr, k, index + 1, count + 1, current_sum + arr[index]) or k_sum_to_100(arr, k, index + 1, count, current_sum)


#### Task 07: Maximum Length Sub-array of Positive Integers

def max_pos_subarray(arr, index=0, current_len=0, max_len=0):
    if index >= len(arr):
        return max_len
    if arr[index] > 0:
        return max_pos_subarray(arr, index + 1, current_len + 1, max(max_len, current_len + 1))
    return max_pos_subarray(arr, index + 1, 0, max_len)


#### Task 08: Three Partitions with Equal Sum

def partition_three_equal(arr, part1=0, part2=0, part3=0, index=0):
    if index == len(arr):
        return part1 == part2 == part3
    return (partition_three_equal(arr, part1 + arr[index], part2, part3, index + 1) or
            partition_three_equal(arr, part1, part2 + arr[index], part3, index + 1) or
            partition_three_equal(arr, part1, part2, part3 + arr[index], index + 1))