#!/usr/bin/python3
"""method that calculates the fewest number of operations needed to
result in exactly n H characters in the file, given a file with a single
H character and you can only do 2 opeations copy all and paste """


def minOperations(n):
    """On succes return an integer
    if n is imposible to  archive return 0 """

    divisor = 2
    next = True
    result = 0

    if (n <= 0):
        return 0

    while(next):
        if (n % divisor == 0):
            n = n/divisor
            result = result + divisor
            divisor = 1
        if (n == 1):
            next = False
        divisor = divisor + 1
    return result
