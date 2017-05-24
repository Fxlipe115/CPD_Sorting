#!/usr/bin/env python

import sys
import cpdsort
import timeit
import random
import functools

def MERGE(A,start,mid,end):
    L = A[start:mid]
    R = A[mid:end]
    i = 0
    j = 0
    k = start
    for l in range(k,end):
        if j >= len(R) or (i < len(L) and L[i] < R[j]):
            A[l] = L[i]
            i = i + 1
        else:
            A[l] = R[j]
            j = j + 1  

def mergeSort(A,p,r):
    if r - p > 1:
        mid = int((p+r)/2)
        mergeSort(A,p,mid)
        mergeSort(A,mid,r)
        MERGE(A,p,mid,r)

sys.setrecursionlimit(10000)
#with open('quick.data','w') as f:

size = 100
print('# Size | Merge Sort | Hybrid Sort | Insertion Sort')
while size <= 1000:
    l = [random.randint(0,1000) for _ in range(size)]
    
    mergeTime = min(timeit.Timer(functools.partial(mergeSort,l,0,size-1)).repeat(3,1000))/1000
    hybridTime = min(timeit.Timer(functools.partial(cpdsort.mergeSort,l,k=50)).repeat(3,1000))/1000
    insertionTime = min(timeit.Timer(functools.partial(cpdsort.insertionSort,l)).repeat(3,1000))/1000
    
    print(str(size) + ' ' + str(mergeTime) + ' ' + str(hybridTime) + ' ' + str(insertionTime))
    
    
    size+=50
