#!/usr/bin/python3
'''
In a text file, there is a single character H.
Your text editor can execute only two operations in this file:
Copy All and Paste. Given a number n,
write a method that calculates the fewest
number of operations needed to result in exactly n H characters in the file.
'''
def minOperations(n):
    if n == 0:
        return 0
    if n == 1:
        return n
    minop = []
    mod = 2
    while n != 1:
        while n % mod == 0:
            n = n // mod
            minop.append(mod)
        mod += 1

    return sum(minop)
