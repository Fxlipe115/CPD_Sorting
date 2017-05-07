def quickSort(arr):
    less = []
    pivotList = []
    more = []
    if len(arr) <= 1:
        return arr
    else:
        pivot = arr[0]
        for i in arr:
            if i < pivot:
                less.append(i)
            elif i > pivot:
                more.append(i)
            else:
                pivotList.append(i)
        less = quickSort(less)
        more = quickSort(more)
        return less + pivotList + more

def heapsort(lst):
  ''' Heapsort. Note: this function sorts in-place (it mutates the list). '''
  # in pseudo-code, heapify only called once, so inline it here
  for start in range(int((len(lst)-2)/2), -1, -1):
    siftdown(lst, start, len(lst)-1)

  for end in range(len(lst)-1, 0, -1):
    lst[end], lst[0] = lst[0], lst[end]
    siftdown(lst, 0, end - 1)
  return lst

def siftdown(lst, start, end):
  root = start
  while True:
    child = root * 2 + 1
    if child > end: break
    if child + 1 <= end and lst[child] < lst[child + 1]:
      child += 1
    if lst[root] < lst[child]:
      lst[root], lst[child] = lst[child], lst[root]
      root = child
    else:
      break

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
    keys = quickSort(keys)
    locks = quickSort(locks)

    l_q_t = []
    for k in keys:
        if k in locks:
            k = decodify(k)
            if len(k) == 4:
                k = '0' + k
            l_q_t.append(k[::-1])

    print(l_q_t)
