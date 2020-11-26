#!/usr/bin/python3
""" calculate how much water will be retained after it rains."""


def rain(walls):
    """return integer indicating total amount of rainwater retained
    if the list is empty return 0"""

    left_max = right_max = water = lo = 0
    hi = len(walls)-1

    if walls is None:
        return 0
    while lo < hi:
        if walls[lo] < walls[hi]:
            if walls[lo] < left_max:
                water += left_max - walls[lo]
            left_max = max(left_max, walls[lo])
            lo += 1
        else:
            if walls[hi] < right_max:
                water += right_max - walls[hi]
            right_max = max(right_max, walls[hi])
            hi -= 1

    return water
