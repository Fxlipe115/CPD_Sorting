import functools
import timeit
import random

def wrapper(func, *args, **kwargs):
    def wrapped():
        return func(*args, **kwargs)
    return wrapped

calls = 0
swaps = 0
partE = []
partD = []
def quickSort(arr):
    less = []
    pivotList = []
    more = []
    if len(arr) <= 1:
        return arr
    else:
        #pivot = arr[0]
        #particionamento aleatorio
        pivot = random.choice(arr)
        #global partE, partD
        #global swaps
        for i in arr:
            if i < pivot:
                less.append(i)
                #swaps += 1
            elif i > pivot:
                more.append(i)
                #swaps += 1
            else:
                pivotList.append(i)
                #swaps += 1
        #partE.append(len(less))
        #partD.append(len(more))

        #global calls
        less = quickSort(less)
        #calls += 1
        more = quickSort(more)
        #calls += 1
        return less + pivotList + more

def codify(string):
    """ Codifies string into base 62 (digits and case sensitive).
        In:
            string:String = string of length to codified.
        Out:
            codif:Integer = integer that represents the string codified.
    """

    codif = 0
    for i in range(len(string)):
        try:
            val = int(string[i])
            codif += val*62**i

        except ValueError:
            if ord(string[i]) < 91:
                val = ord(string[i]) - 55
            else:
                val = ord(string[i]) - 61

            codif += val*62**i

    return codif

def decodify(num, b=62, numerals="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"):
    """ Got from
    http://stackoverflow.com/questions/2267362/how-to-convert-an-integer-in-any-base-to-a-string"""

    return ((num == 0) and numerals[0]) or (decodify(num // b, b, numerals).lstrip(numerals[0]) + numerals[num % b])

def read_f(file_p):
    f = open(file_p, 'r')
    lout = []
    for line in f:
        lout.append(codify(line.strip()))

    return lout

if __name__ == '__main__':
    keys = read_f('./chaves.txt')
    locks = read_f('./cadeados.txt')

    wrapped = wrapper(quickSort, keys)
    print(timeit.timeit(wrapped, number=1000))
    #print(max(partD))
    #print(min(partD))
    #print(max(partE))
    #print(min(partE))
    #print(sum(partE)/len(partE))
    #print(sum(partD)/len(partD))

    swaps = 0
    partE = []
    partD = []
    wrapped = wrapper(quickSort, locks)
    print(timeit.timeit(wrapped, number=1000))
    #print(max(partE))
    #print(min(partE))
    #print(max(partD))
    #print(min(partD))
    #print(sum(partE)/len(partE))
    #print(sum(partD)/len(partD))

    l_q_t = []
    for k in keys:
        if k in locks:
            k = decodify(k)
            if len(k) == 4:
                k = '0' + k
            l_q_t.append(k[::-1])

    #print(l_q_t)
