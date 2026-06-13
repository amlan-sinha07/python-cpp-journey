class Node:
    def __init__(self,value):
        self.value=value
        self.left=None
        self.right=None
class BST:
    def __init__(self):
        self.root=None
    def insert(self,value):
        if self.root is None:
            self.root=Node(value)
        else:
            self._insert(self.root,value)
    def _insert(self,node,value):
        if value<node.value:
            if node.left is None:
                node.left=Node(value)
            else:
                self._insert(node.left,value)
        else:
            if node.right is None:
                node.right=Node(value)
            else:
                self._insert(node.right,value)
    def search(self,node,value):
        if node is None:
            print("not found",value)
            return False
        if value==node.value:
            print("Found! ",value)
            return True
        elif value<node.value:
            return self.search(node.left,value)
        elif value>node.value:
            return self.search(node.right,value)
    def inorder(self,node):
        if node:
            self.inorder(node.left)
            print(node.value)
            self.inorder(node.right)
    def height(self,node):
        if node is None:
            return 0
        return 1+ max(self.height(node.left),self.height(node.right))
    def delete(self, node, value):
        if node is None:
            print("deleting element not found")
            return node
        if value>node.value:
            node.right=self.delete(node.right,value)
        elif value<node.value:
            node.left=self.delete(node.left,value)
        else:
            if node.left is None:
                return node.right
            if node.right is None:
                return node.left
            temp=self._min_value_node(node.right)
            node.value=temp.value
            node.right=self.delete(node.right,temp.value)
        return node
    def _min_value_node(self,node):
        current=node
        while current.left is not None:
            current=current.left
        return current
bst=BST()
for x in [8,5,7,4,3,10,1,6,14,99,50,11]:
    bst.insert(x)
print(bst.search(bst.root,6))
print(bst.search(bst.root,9))
bst.inorder(bst.root)
print("Height:",bst.height(bst.root))
bst.root=bst.delete(bst.root,10)
bst.inorder(bst.root)