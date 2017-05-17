from math import log

def mergeSort(l,key=None,reverse=False):
    if key is None:
        key = lambda x: x
    size = len(l)
    if size <= 1:
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


def insertionSort(l):
    for i in range(1, len(l)):
        j = i-1
        key = l[i]
        while (l[j] > key) and (j >= 0):
           l[j+1] = l[j]
           j -= 1
        l[j+1] = key


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
        passes = int(round(log(max(abs(min(l)),max(l)),radix)) + 1)
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
    l = [7.423,6,5,4.512342,3,1,6,3,-1,4.512341,2,-2,7.217,8,0]
    print(radixSort(l))
    print(radixSort(l,radix=2))
