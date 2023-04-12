from abc import ABCMeta, abstractmethod
class MyList(object):
    __metaclass__ = ABCMeta
    def len(self):
        pass
    def getitem(self, j):
        pass
    def setitem(self, val, j):
        pass
    def insertItem(self, item, j=0):
        pass
    def removeItem(self, j=0):
        pass
    def printMyList(self):
        pass
    
class ArrayBasedList(MyList):
    length = 0
    def __init__(self, size):
        self.item = size*[None]
        self.length = 0
    def len(self):
        return self.length
    def getitem(self, j):
        if(self.len() > j):
            return self.item[j]
        raise ValueError('index is out of bound')
    def setitem(self, val, j):
        if(self.len() > j):
            self.item[j] = val
            return
        raise ValueError('index is out of bound')
    def insertItem(self, item, j=0):
        if(self.len() >= j):
            for i in range(self.len(), j, -1):
                self.item[i] = self.item[i - 1]
            self.item[j] = item
            self.length += 1
            return
        raise ValueError('index is out of bound')
    def removeItem(self, j=0):
        if(self.len() > j):
            for i in range(j, self.len() - 1, 1):
                self.item[i] = self.item[i + 1]
            self.length -= 1
            return
        raise ValueError('index is out of bound')
    def printMyList(self):
        if(self.len() > 0):
            for i in range(self.len()):
                print(self.item[i], end=" ")
            print()
            return
        print('list is empty')
        
        
test = ArrayBasedList(10)

test.insertItem(4, 0)
test.insertItem(3, 0)
test.insertItem(1, 0)
test.insertItem(2, 1)

test.printMyList()

test.removeItem(3)
test.removeItem(1)
test.removeItem(0)

test.printMyList()

