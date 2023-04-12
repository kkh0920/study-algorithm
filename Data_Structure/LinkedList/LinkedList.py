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

class Node(object):
    def __init__(self, data=None, next_node=None): 
        self.data = data
        self.next_node = next_node
    def get_data(self): 
        return self.data
    def set_data(self, data):
        self.data = data
    def get_next(self): 
        return self.next_node
    def set_next(self, new_next): 
        self.next_node = new_next

class LinkedList(MyList):
    def __init__(self, head=None):
        self.head = None
        self.length = 0
    def len(self):
        return self.length
    def getitem(self, j):
        if(self.len() > j):
            cursor = self.head
            for i in range(j):
                cursor = cursor.get_next()
            return cursor.get_data()
        raise ValueError('index is out of bound')
    
    def setitem(self, val, j):
        if(self.len() > j):
            cursor = self.head
            for i in range(j):
                cursor = cursor.get_next()
            cursor.set_data(val)
            return
        raise ValueError('index is out of bound')
    
    def insertItem(self, item, j=0):
        if(self.len() >= j):
            self.length += 1
            newNode = Node()
            newNode.set_data(item)
            if(self.head == None):
                self.head = newNode
                return
            prev = None
            current = self.head
            for i in range(j):
                prev = current
                current = current.get_next()
            if(prev == None):
                newNode.set_next(current)
                self.head = newNode
                return
            prev.set_next(newNode)
            if(current != None):
                newNode.set_next(current)
            return
        raise ValueError('index is out of bound')
    
    def removeItem(self, j=0):
        if(self.len() > j):
            self.length -= 1
            prev = None
            current = self.head
            for i in range(j):
                prev = current
                current = current.get_next()
            if(prev == None):
                self.head = self.head.get_next()
                return
            if(current.get_next() != None):
                prev.set_next(current.get_next())
                return
            prev.set_next(None)
            return
        raise ValueError('index is out if bound')
    
    def printMyList(self):
        if(self.len() > 0):
            cursor = self.head
            for i in range(self.len()):
                print(cursor.get_data(), end=" ")
                cursor = cursor.get_next()
            print()
            return
        print('list is empty')
        
test = LinkedList()

test.insertItem(4, 0)
test.insertItem(3, 0)
test.insertItem(1, 0)
test.insertItem(2, 1)

test.printMyList()

test.removeItem(3)
test.removeItem(1)
test.removeItem(0)

test.printMyList()
