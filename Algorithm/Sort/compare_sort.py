import numpy as np
import time

def insertion_sort(data):
    for i in range(1, len(data)):
        key = data[i]
        j = i - 1
        while j >= 0 and int(data[j]) > int(key):
            data[j + 1] = data[j]
            j -= 1
        data[j + 1] = key 

def selection_sort(data):
    for i in range(len(data)):
        min_index = i
        for j in range(i + 1, len(data)):
            if int(data[j]) < int(data[min_index]):
                min_index = j
        data[i], data[min_index] = data[min_index], data[i]    

def heap_sort(data):
    def heapify(data, n, i):
        largest = i  
        left = 2 * i + 1
        right = 2 * i + 2
        if left < n and int(data[left]) > int(data[largest]): 
            largest = left
        if right < n and int(data[right]) > int(data[largest]): 
            largest = right
        if largest != i:  
            data[i], data[largest] = data[largest], data[i]
            heapify(data, n, largest)
            
    n = len(data)
    for i in range(n // 2 - 1, -1, -1):
        heapify(data, n, i)
    for i in range(n - 1, 0, -1):
        data[i], data[0] = data[0], data[i] 
        heapify(data, i, 0)  

def merge_sort(data):
    def merge(left, right):
        l = 0
        r = 0
        merged = []
        while l < len(left) and r < len(right):
            if int(left[l]) > int(right[r]):
                merged.append(right[r])
                r += 1
            else:
                merged.append(left[l])
                l += 1
        while l < len(left):
            merged.append(left[l])
            l += 1
        while r < len(right):
            merged.append(right[r])
            r += 1
        return merged

    if len(data) <= 1:
        return data
    mid = len(data) // 2
    left = merge_sort(data[:mid])
    right = merge_sort(data[mid:])
    return merge(left, right)
    
def quick_sort(data):
    if len(data) <= 1:
        return data
    pivot = data[len(data) // 2]
    left, equal, right = [], [], []
    for num in data:
        if int(num) < int(pivot):
            left.append(num)
        elif num == pivot:
            equal.append(num)
        else:
            right.append(num)
    return quick_sort(left) + equal + quick_sort(right)

def built_in_sort(data):
    data.sort()
    

data_files = ['test1.dat', 'test2.dat', 'test3.dat', 'test4.dat', 'test5.dat']

strFormat = '%-20s%-15s%-15s%-15s%-15s%-15s'
strOut = strFormat % (' ', '500', '1K', '5K', '10K', '100K')
print(strOut)

print('%10s' % "selection", end=" ")
for f in data_files:
    data_file = open("/Users/kkh1535/dataset/{0}".format(f), 'r')
    data = data_file.readlines()
    
    start = time.time()
    selection_sort(data)
    end = time.time()
    print('%15s' % f"{(end - start) * 1000:.2f}ms", end=' ')
print()

print('%10s' % "heap", end=" ")
for f in data_files:
    data_file = open("/Users/kkh1535/dataset/{0}".format(f), 'r')
    data = data_file.readlines()
    
    start = time.time()
    heap_sort(data)
    end = time.time()
    print('%15s' % f"{(end - start) * 1000:.2f}ms", end=' ')
print()
    
print('%10s' % "insertion", end=" ")
for f in data_files:
    data_file = open("/Users/kkh1535/dataset/{0}".format(f), 'r')
    data = data_file.readlines()
    
    start = time.time()
    insertion_sort(data)
    end = time.time()
    print('%15s' % f"{(end - start) * 1000:.2f}ms", end=' ')
print()

print('%10s' % "quick", end=" ")
for f in data_files:
    data_file = open("/Users/kkh1535/dataset/{0}".format(f), 'r')
    data = data_file.readlines()
    
    start = time.time()
    quick_sort(data)
    end = time.time()
    print('%15s' % f"{(end - start) * 1000:.2f}ms", end=' ')
print()

print('%10s' % "merge", end=" ")
for f in data_files:
    data_file = open("/Users/kkh1535/dataset/{0}".format(f), 'r')
    data = data_file.readlines()
    
    start = time.time()
    merge_sort(data)
    end = time.time()
    print('%15s' % f"{(end - start) * 1000:.2f}ms", end=' ')
print()

print('%10s' % "python", end=" ")
for f in data_files:
    data_file = open("/Users/kkh1535/dataset/{0}".format(f), 'r')
    data = data_file.readlines()
    
    start = time.time()
    built_in_sort(data)
    end = time.time()
    print('%15s' % f"{(end - start) * 1000:.2f}ms", end=' ')
print()

data_file.close()