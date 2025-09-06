class ListNode:

    def __init__(self,val = 0):
        self.val = val
        self.next = None

class MyLinkedList:

    def __init__(self):
        self.head = None
        self.size = 0

    def get(self, index: int) -> int:
        if index >= self.size:
            return -1
        currNode = self.head
        for _ in range(index):
            currNode = currNode.next
        return currNode.val

    def addAtHead(self, val: int) -> None:
        newNode = ListNode(val)
        newNode.next = self.head
        self.head = newNode
        self.size += 1

    def addAtTail(self, val: int) -> None:
        if self.head is None:
            self.addAtHead(val)
            return
        else:
            currNode = self.head
            while currNode.next != None:
                currNode = currNode.next
            newNode = ListNode(val)
            currNode.next = newNode
        self.size += 1

    def addAtIndex(self, index: int, val: int) -> None:
        if index > self.size:
            return
        if index == 0:
            self.addAtHead(val)
        else:
            currNode = self.head
            for _ in range(index-1):
                currNode = currNode.next
            newNode = ListNode(val)
            newNode.next = currNode.next
            currNode.next = newNode
        self.size += 1

    def deleteAtIndex(self, index: int) -> None:
        if self.size <= index:
            return
        if index == 0:
            self.head = self.head.next
        else:
            currNode = self.head
            for _ in range(index-1):
                currNode = currNode.next
            currNode.next = currNode.next.next
        self.size -= 1


# Your MyLinkedList object will be instantiated and called as such:
# obj = MyLinkedList()
# param_1 = obj.get(index)
# obj.addAtHead(val)
# obj.addAtTail(val)
# obj.addAtIndex(index,val)
# obj.deleteAtIndex(index)