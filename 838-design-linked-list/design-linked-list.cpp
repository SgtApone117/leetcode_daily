struct Node
{
    int val;
    struct Node *next;
};
class MyLinkedList {
private:
    Node *head;
    int size;
public:
    MyLinkedList() {
        size = 0;
        head = nullptr;
    }
    
    int get(int index) {
        if(index >= size)
        {
            return -1;
        }
        struct Node* currNode = head;
        for(int i = 0; i < index; i++)
        {
            currNode = currNode->next;
        }
        return currNode->val;
    }
    
    void addAtHead(int val) {
        struct Node *newNode = new Node;
        newNode->val = val;
        newNode->next = head;
        head = newNode;
        size++;
    }
    
    void addAtTail(int val) {
        if(head == nullptr)
        {
            addAtHead(val);
            return;
        }
        struct Node* newNode = new Node;
        newNode->val = val;
        newNode->next = nullptr;
        struct Node* currNode = head;
        while(currNode->next)
        {
            currNode = currNode->next;
        }
        currNode->next = newNode;
        size++;
    }
    
    void addAtIndex(int index, int val) {
        if(index > size)
        {
            return;
        }
        else if(index == 0)
        {
            addAtHead(val);
            return;
        }
        else if(index == size)
        {
            addAtTail(val);
            return;
        }
        else
        {
            struct Node* currNode = head;
            for(int i = 0; i < index-1; i++)
            {
                currNode = currNode->next;
            }
            struct Node* newNode = new Node;
            newNode->val = val;
            newNode->next = currNode->next;
            currNode->next = newNode;
        }
        size++;
    }
    
    void deleteAtIndex(int index) {
        if(index >= size)
        {
            return;
        }
        else if(index == 0)
        {
            head = head->next;
        }
        else
        {
            struct Node* currNode = head;
            for(int i = 0; i < index-1; i++)
            {
                currNode = currNode->next;
            }
            currNode->next = currNode->next->next;
        }
        size--;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */