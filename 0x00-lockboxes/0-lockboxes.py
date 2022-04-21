#!/usr/bin/python3
'''
have n number of locked boxes in front of you.
Each box is numbered sequentially from 0 to n - 1
and each box may contain keys to the other boxes.

A key with the same number as a box opens that box
The first box boxes[0] is unlocked
Return True if all boxes can be opened, else return False
'''


def canUnlockAll(boxes):
    '''
    Method that determines if all the boxes can be opened.
    '''
    unlock = [0]
    lenbox = len(boxes)
    for i in unlock:
        for key in boxes[i]:
            if key not in unlock and key < lenbox:
                unlock.append(key)
    if len(unlock) != len(boxes):
        return False
    return True
