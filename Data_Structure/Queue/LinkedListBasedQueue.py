from abc import ABCMeta, abstractmethod # need these definitions
class MyQueue(object):
    """Our own version of collections.Sequence abstract base class.""" 
    __metaclass__ = ABCMeta
    @abstractmethod
    def len(self):
        """returns the number of elements stored.""" 
        pass
    @abstractmethod
    def first(self):
        """returns the element at the front without removing it.""" 
        pass
    @abstractmethod
    def is_empty(self):
        """returns whether no elements are stored.""" 
        pass
    @abstractmethod
    def enqueue(self, item):
        """Add an item into the queue.""" 
        pass
    @abstractmethod
    def dequeue(self):
        """Remove an item from the queue.""" 
        pass
    @abstractmethod
    def printMyQueue(self):
        """Print the items in the queue.""" 
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
        
class LinkedListBasedQueue(MyQueue):
    def __init__(self, head=None, tail=None): 
        self.head = None
        self.tail = None
        self.length = 0
    def len(self):
        return self.length
    def first(self): 
        if(not self.is_empty()):
            return self.head.data
        raise ValueError('queue is empty')
    def is_empty(self):
        if(self.len() > 0):
            return False
        return True
    def enqueue(self, item):
        newNode = Node()
        newNode.set_data(item) 
        if(self.is_empty()):
            self.head = newNode
            self.length += 1
            return
        cursor = self.head
        while cursor.get_next() != None:
            cursor = cursor.get_next()
        cursor.set_next(newNode)
        self.length += 1
    def dequeue(self):
        if(not self.is_empty()):
            self.length -= 1
            self.head = self.head.get_next()
            return
        print('queue is empty')
    def printMyList(self):
        if(not self.is_empty()):
            cursor = self.head
            for i in range(self.len()):
                print(cursor.data, end=" ")
                cursor = cursor.get_next()
            print()
            return
        print('queue is empty')
        
q = LinkedListBasedQueue()

q.enqueue(5)
q.enqueue(3)

q.printMyList()
print(q.len())

q.dequeue()
q.dequeue()

if(q.is_empty()):
    print("queue is empty")
else:
    print("not empty")
    
q.dequeue()

q.enqueue(7)
q.enqueue(9)

print(q.first())
