#!/usr/bin/python3
def canUnlockAll(boxes):
    """method that determines if all the boxes can be opened.
    return true if all baxes can be opened, else return False"""
    if not boxes or (type(boxes) != list) or len(boxes) < 1:
        return False
    keyList = []
    countBoxes = len(boxes)
    boxesUnlock = setBoxesUnlock(countBoxes)
    for i in range(countBoxes):
        if(type(boxes[i]) == list):
            if i == 0:
                keyList.append(0)
                setKeys(boxes[i], keyList, boxesUnlock)
            if boxesUnlock[i] == 0 and keyList.count(i) > 0:
                keyList = unlockBox(keyList, boxesUnlock, boxes)
        else:
            return False
    if boxesUnlock.count(0) == 0:
        return True
    return False


def unlockBox(keys, boxesUnlock, boxes):
    """method that unlock a box."""
    if len(keys) > 0:
        if keys[0] < len(boxesUnlock):
            boxesUnlock[keys[0]] = 1
            if not boxes[keys[0]] or (type(boxes[keys[0]]) == list):
                setKeys(boxes[keys[0]], keys, boxesUnlock)
            keys.pop(0)
            unlockBox(keys, boxesUnlock, boxes)
    return keys


def setKeys(box, keyList, boxesUnlock):
    """method that set the keys for an unlock box."""
    if box:
        for key in box:
            if isInteger(key):
                if key < len(boxesUnlock):
                    if keyList.count(key) == 0 and boxesUnlock[key] == 0:
                        keyList.append(key)


def setBoxesUnlock(count):
    """method that initialize all unlock boxes"""
    boxes = []
    for i in range(count):
        boxes.append(0)
    return boxes


def isInteger(str):
    """method that deternime if an string is integer"""
    is_int = True
    try:
        int(str)
    except ValueError:
        is_int = False
    return is_int
