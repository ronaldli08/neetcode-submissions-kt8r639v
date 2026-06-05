class MyLinkedList {
public:

    struct Node{
        int val;
        Node* next;
    };

    int val;
    Node* dummy;
    int size;

    MyLinkedList() {
        dummy = new Node{0, nullptr};
        size = 0;
    }
    
    int get(int index) {
        if(index >= size) return -1;
        Node* cur = dummy->next;
        for(int i = 0; i < index; ++i) {
            cur = cur->next;
        }
        return cur->val;
    }
    
    void addAtHead(int val) {
        addAtIndex(0,val);
    }
    
    void addAtTail(int val) {
        addAtIndex(size, val);
    }
    
    void addAtIndex(int index, int val) {
        if(index > size) return;
        Node* prev = dummy;
        for(int i = 0; i < index; ++i) {
            prev = prev->next;
        }
        Node* newNode = new Node{val, prev->next};
        prev->next = newNode;
        ++size;
    }
    
    void deleteAtIndex(int index) {
        if(index >= size) return;
        Node* prev = dummy;
        for(int i = 0; i < index; ++i) {
            prev = prev->next;
        }
        Node* cur = prev->next;
        prev->next = cur->next;
        delete cur;
        --size;
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