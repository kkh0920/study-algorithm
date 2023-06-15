from bintrees import BinaryTree
from bintrees import AVLTree

btree = BinaryTree()
avltree = AVLTree()

# foreach(f, [order]) 
# -> visit all nodes of tree (0 = ‘inorder’, -1 = ‘preorder’ or +1 = ‘postorder’) and 
# call f(k, v) for each node, O(n)

def func(k, v):
    print(k, end=' ')

# <BSTree Traversal>

# Insert(5, 3, 6, 7, 4, 1, 9)
btree.insert(5, None)
btree.insert(3, None)
btree.insert(6, None)
btree.insert(7, None)
btree.insert(4, None)
btree.insert(1, None)
btree.insert(9, None)

# 1.
print("<Binary Search Tree>")
print("In-order :", end=' ')
btree.foreach(func, 0)
print()

print("Pre-order :", end=' ')
btree.foreach(func, -1)
print()

print("Post-order :", end=' ')
btree.foreach(func, 1)
print()
print()

# Remove(1, 3, 5, 7, 9)
btree.remove(1)
btree.remove(3)
btree.remove(5)
btree.remove(7)
btree.remove(9)

# 2.
print("In-order :", end=' ')
btree.foreach(func, 0)
print()

print("Pre-order :", end=' ')
btree.foreach(func, -1)
print()

print("Post-order :", end=' ')
btree.foreach(func, 1)
print()
print()


# <AVLTree Traversal>

# Insert(5, 3, 6, 7, 4, 1, 9)
avltree.insert(5, None)
avltree.insert(3, None)
avltree.insert(6, None)
avltree.insert(7, None)
avltree.insert(4, None)
avltree.insert(1, None)
avltree.insert(9, None)

# 3.
print("<AVL Tree>")
print("In-order :", end=' ')
avltree.foreach(func, 0)
print()

print("Pre-order :", end=' ')
avltree.foreach(func, -1)
print()

print("Post-order :", end=' ')
avltree.foreach(func, 1)
print()
print()

# Remove(1, 3, 5, 7, 9)
avltree.remove(1)
avltree.remove(3)
avltree.remove(5)
avltree.remove(7)
avltree.remove(9)

# 4.
print("In-order :", end=' ')
avltree.foreach(func, 0)
print()

print("Pre-order :", end=' ')
avltree.foreach(func, -1)
print()

print("Post-order :", end=' ')
avltree.foreach(func, 1)
print()