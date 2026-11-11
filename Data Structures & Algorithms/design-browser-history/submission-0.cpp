class BrowserHistory {
    struct Page{
        string url;
        Page* next;
        Page* prev;
        Page(string u, Page *n, Page *p): url(u), next(n), prev(p){}
        Page(string u, Page *p): url(u), next(nullptr), prev(p){}
        Page(string u): url(u), next(nullptr), prev(nullptr){}

    };
private:
    Page* tail, *cur;
    int size = 1, pos = 1;
public:
    BrowserHistory(string homepage) {
        Page* home_page = new Page(homepage);
        cur = home_page;
    }
    
    void visit(string url) {
        Page* next_page = new Page(url,cur);
        cur->next = next_page;
        cur = next_page;
        if (pos != size){
            size = pos;
        }
        pos++;
        size++;
    }
    
    string back(int steps) {
        if(steps > pos-1){
            steps = pos-1;
        }
        for(int i = 0; i < steps; i++){
            cur = cur->prev;
        }
        pos = pos - steps;
        return cur->url;
    }
    
    string forward(int steps) {
        if(steps > size-pos){
            steps = size-pos;
        }
        for(int i = 0; i < steps; i++){
            cur = cur->next;
        }
        pos = pos + steps;
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