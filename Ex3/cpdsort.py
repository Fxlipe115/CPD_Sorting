from math import log

def radixSort(li,radix=10):
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
    
    print('')
    print(radixSort(l))
    print(radixSort(l2))