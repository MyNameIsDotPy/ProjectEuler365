CollatzSequenceMap = {}

def CollatzSequence(n):
    if n == 1:
        return 1
    if n % 2 != 0:
        if n not in CollatzSequenceMap.keys():
            length = 1 + CollatzSequence(3 * n + 1)
            CollatzSequenceMap[n] = length
            return length
        return CollatzSequenceMap[n]
    if n not in CollatzSequenceMap.keys():
        length = 1 + CollatzSequence(n // 2)
        CollatzSequenceMap[n] = length
        return length
    return CollatzSequenceMap[n]

def reto14():
    max_n = 1
    idx = 1
    for i in range(1, 1000000):
        num = CollatzSequence(i)
        if num > max_n:
            max_n = num
            idx = i
    return idx




print(reto14())
