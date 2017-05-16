def mergeSort(l):
    size = len(l)
    if size <= 1:
        return l
    else:
        middle = size//2
        llist = mergeSort(l[:middle])
        rlist = mergeSort(l[middle:])

        return merge(llist,rlist)
		
def merge(left,right):
    if len(left) > 0 and len(right) > 0:
            v = left.pop(0) if left[0] < right[0] else right.pop(0)
            return [v] + merge(left,right)
    else:
            return left + right

if __name__ == '__main__':
    l = [7,6,5,4,3,1,6,3,4,2,7,8,0]
    print(mergeSort(l))
