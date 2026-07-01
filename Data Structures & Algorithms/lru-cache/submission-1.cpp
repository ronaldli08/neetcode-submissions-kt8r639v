class LRUCache {
public:
    struct ListNode{
        int key;
        int val;
        ListNode* next;
        ListNode* prev;
    };
    map<int, ListNode*> addr;
    int c;
    int count;
    ListNode* head;
    ListNode* tail;
    LRUCache(int capacity) {
        c = capacity;
        count = 0;
        head = new ListNode();
        tail = new ListNode();
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(addr[key] == nullptr) return -1;
        unlink(addr[key]);
        addFront(addr[key]);
        return addr[key]->val;
    }
    
    void put(int key, int value) {
        if(addr[key] != nullptr) {
            ListNode* node = addr[key];
            node->val = value;
            unlink(node);
            addFront(node);
        }
        else {
            ListNode* node = new ListNode{key, value, nullptr, nullptr};
            addr[key] = node;
            addFront(node);
            count++;
            if(count > c) {
ListNode* lru = tail->prev;
        unlink(lru);
        addr.erase(lru->key);
        delete lru;
        --count;
            }
        }
    }
    void remove(ListNode* node) {
        if(addr[node->key] == nullptr) return;
        --count;
        ListNode* oldprev = addr[node->key]->prev;
        ListNode* oldnext = addr[node->key]->next;
        if(oldprev != nullptr) {
            oldprev->next = oldnext;
        }
        if(oldnext != nullptr) {
            oldnext->prev = oldprev;
        }
        delete node;
    }

    void unlink(ListNode* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }void addFront(ListNode* node) {
    node->next = head->next;
    node->prev = head;
    head->next->prev = node;
    head->next = node;
}

    void addBack(ListNode* node) {
        node->prev = tail;
        tail->next = node;
        tail = node;
        ++count;
        if(count > c) {
            ListNode* old = head;
            head = head->next;
            delete old;
            --count;
        }
    }
};

