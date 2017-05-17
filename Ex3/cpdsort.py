from math import log

def mergeSort(l,key=None,reverse=False,k=0):
    if key is None:
        key = lambda x: x
    size = len(l)
    if size == k:
        return insertionSort(l)
    elif size <= 1:
        return l
    else:
        middle = size//2
        llist = mergeSort(l[:middle],key,reverse)
        rlist = mergeSort(l[middle:],key,reverse)

        return _merge(llist,rlist,key,reverse)

def _merge(left,right,key,reverse=False):
    f = (lambda x,y: x > y) if reverse else (lambda x,y: y > x)
    if len(left) > 0 and len(right) > 0:
            v = left.pop(0) if f(key(left[0]),key(right[0])) else right.pop(0)
            return [v] + _merge(left,right,key,reverse)
    else:
            return left + right


def insertionSort(l,key=None,reverse=False):
    if key is None:
        key = lambda x: x
    for i in range(1, len(l)):
        j = i-1
        chave = key(l[i])
        obj = l[i]
        while ((key(l[j]) < chave) if reverse else (key(l[j]) > chave)) and (j >= 0):
           l[j+1] = l[j]
           j -= 1
        l[j+1] = obj
    return l


def radixSort(li,radix=10,msd=False):
    l2 = [[],[]]
    for i in li:
        if i < 0:
            l2[0].append(i)
        else:
            l2[1].append(i)
    for l in l2:
        for i,j in enumerate(l):
            l[i] = int(j * (10**6))
        try:
            passes = int(round(log(max(abs(min(l)),max(l)),radix)) + 1)
        except ValueError:
            passes = 0
        for i in range(passes):
            buckets = [[] for _ in range(radix)]
            for n,x in enumerate(l):
                buckets[x // radix**i % radix].append(x)
            l.clear()
            for m in buckets:
                l.extend(m)
        for i,j in enumerate(l):
            l[i] = j / (10**6)
    return l2[0] + l2[1]



if __name__ == '__main__':
    l = [34.234, 45.34, 67.21, 7.5674, 234.98, 123.321, 65.78, 84.001, 0.0001, 9.0123]
    l2 = [-34.234, 45.34, -67.21, 7.5674, -234.98, 123.321, -65.78, 84.001, -0.0001, 9.0123]
    print(radixSort(l))
    print(radixSort(l,radix=2))
    print(radixSort(l2))
    print(radixSort(l2,radix=2))
