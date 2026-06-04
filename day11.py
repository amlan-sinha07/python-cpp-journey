arr=[64,25,12,22,11]

def linear_search(arr: list,target: int)->int:
    for index,element in enumerate(arr):
        if element==target:
            return index
        
    return -1
result=linear_search(arr,22)
if result !=-1:
    print(f"found at index {result}")
else:
    print("target not found")
arr.sort()







def binary_search(arr: list,target: int)->int:
    left=0
    right=len(arr)-1
    while left<=right:
        mid=(right+left)//2
        if arr[mid]==target:
            return mid
        elif arr[mid]<target:
            left=mid+1
        else:
            right=mid-1
arr=[11,12,22,25,64]
print(binary_search(arr,25))
print(binary_search(arr,99))
print(binary_search(arr,11))








def bubble_sort(arr:list)->list:
    n=len(arr)
    for i in range(n):
        swapped=False
        for j in range(0,n-i-1):
            if arr[j]>arr[j+1]:
                arr[j],arr[j+1]=arr[j+1],arr[j]
                swapped=True
        if not swapped:
            break
    return arr
arr=[12,11,64,25,22]
print(bubble_sort(arr))
class Node:
    def __init__(self,value):
        self.value=value
        self.next=None
class LinkedList:
    def __init__(self):
        self.head=None
    def append(self,value):
        new_Node=Node(value)
        if self.head is None:
            self.head=new_Node
            return
        current=self.head
        while current.next is not None:
            current=current.next
        current.next=new_Node
    def prepend(self,value):
        new_Node=Node(value)
        if self.head is not None:
            new_Node.next=self.head
        self.head=new_Node
        
    def search(self,target):
        current=self.head
        while current is not None:
            if current.value==target:
                return True
            current=current.next
        return False
    def print_list(self):
        current=self.head
        while current is not None:
            print(current.value,end="->")
            current=current.next
        print("NULL")
n1=Node(11)
n2=Node(22)
n1.next=n2
ll=LinkedList()

ll.append(11)
ll.append(22)
ll.append(33)
ll.prepend(5)
ll.print_list()
print(ll.search(22))
print(ll.search(95))
print(n1.value)
print(n1.next.value)
print(n2.next)