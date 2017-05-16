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

if __name__ == '__main__':
    l = [7,6,5,4,3,1,6,3,4,2,7,8,0]
    print(mergeSort(l))
