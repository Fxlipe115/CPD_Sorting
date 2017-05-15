def mergeSort(l):
    size = len(l)
    if size <= 1:
        return l
    else:
        middle = size//2
        llist = mergeSort(l[:middle])
        rlist = mergeSort(l[middle:])

        l.clear()
        stop = False
        linserted, rinserted = False, False
        while not stop:
            try:
                if not linserted:
                    lvalue = llist.pop(0)
                    linserted = False
                if not rinserted:
                    rvalue = rlist.pop(0)
                    rinserted = False
            except IndexError:
                stop = True
            else:
                if lvalue < rvalue:
                    value = lvalue
                    linserted = True
                else:
                    value = rvalue
                    rinserted = True
                l.append(value)
        return l + llist + rlist

if __name__ == '__main__':
    l = [7,6,5,4,3,1,6,3,4,2,7,8,0]
    print(mergeSort(l))
