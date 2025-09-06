class MyLinkedList {
private:
    struct Node
    {
        int val;
        std::unique_ptr<Node> next;

        Node(int v) : val(v), next(nullptr) {}
    };
    std::unique_ptr<Node> head;
    Node *tail;
    int size;
public:
    MyLinkedList() : head(nullptr),tail(nullptr),size(0) {}
    
    int get(int index) {
        if(index < 0 || index >= size)
        {
            return -1;
        }
        Node* currNode = head.get();
        for(int i = 0; i < index; i++)
        {
            currNode = currNode->next.get();
        }
        return currNode->val;
    }
    
    void addAtHead(int val) {
        auto newNode = std::make_unique<Node>(val);
        newNode->next = std::move(head);
        head = std::move(newNode);
        if(size == 0)
        {
            tail = head.get();
        }
        size++;
    }
    
    void addAtTail(int val) {
        auto newNode = std::make_unique<Node>(val);
        if(size == 0)
        {
            head = std::move(newNode);
            tail = head.get();
        }
        else
        {
            tail->next = std::move(newNode);
            tail = tail->next.get();
        }
        size++;
    }
    
    void addAtIndex(int index, int val) {
        if(index < 0 || index > size)
        {
            return;
        }
        if(index == 0)
        {
            addAtHead(val);
            return;
        }
        if(index == size)
        {
            addAtTail(val);
            return;
        }
        Node* currNode = head.get();
        for(int i = 0; i < index-1; i++)
        {
            currNode = currNode->next.get();
        }
        auto newNode = std::make_unique<Node>(val);
        newNode->next = std::move(currNode->next);
        currNode->next = std::move(newNode);
        size++;
    }
    
    void deleteAtIndex(int index) {
        if(index < 0 || index >= size)
        {
            return;
        }
        size--;
        if(index == 0)
        {
            head = std::move(head->next);
            if(size == 0)
            {
                tail = nullptr;
            }
            return;
        }
        Node* currNode = head.get();
        for(int i = 0; i < index-1; i++)
        {
            currNode = currNode->next.get();
        }
        currNode->next = std::move(currNode->next->next);
        if(!currNode->next)
        {
            tail = currNode;
        }
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