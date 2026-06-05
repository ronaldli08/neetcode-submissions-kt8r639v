class BrowserHistory {
public:

    struct Page{
        string url;
        Page* next;
        Page* prev;
    };

    Page* dummy;
    Page* cur;

    BrowserHistory(string homepage) {
        dummy = new Page{homepage, nullptr, nullptr};
        cur = dummy;
    }
    
    void visit(string url) {
        Page* page = new Page{url, nullptr, cur};
        cur->next = page;
        cur = page;
    }
    
    string back(int steps) {
        while (steps > 0 && 
                cur != nullptr && 
                cur->prev != nullptr) {
            cur = cur->prev;
            --steps;
        }
        return cur->url;
    }
    
    string forward(int steps) {
        while (steps > 0 && 
                cur != nullptr && 
                cur->next != nullptr) {
            cur = cur->next;
            --steps;
        }
        return cur->url;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */