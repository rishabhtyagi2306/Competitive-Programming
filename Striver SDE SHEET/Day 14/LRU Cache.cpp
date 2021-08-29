class LRUCache {
public:
    class Node{
    public:
        int key;
        int val;
        Node *prev;
        Node *next;
        Node(int _key, int _val)
        {
            val = _val;
            key = _key;
        }
    };
    
    
    Node *head = new Node(-1, -1);
    Node *tail = new Node(-1, -1);
    
    int cap;
    map<int, Node*> mp;
    
    LRUCache(int capacity) {
        cap = capacity;
        head -> next = tail;
        tail -> prev = head;
    }
    
    void deleteNode(Node *curr)
    {
        Node *tmp = curr -> prev;
        tmp -> next = curr -> next;
        curr -> next -> prev = tmp;
    }
    
    void addNode(Node *curr)
    {
        curr -> next = head -> next;
        head -> next -> prev = curr;
        head -> next = curr;
        curr -> prev = head;
    }
    
    int get(int key) {
        if(mp.find(key) != mp.end())
        {
            Node *curr = mp[key];
            int res = curr -> val;
            mp.erase(key);
            
            deleteNode(curr);
            addNode(curr);
            
            mp[key] = head -> next;
            
            return curr -> val;
        }
        else
        {
            return -1;
        }
    }
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end())
        {
            Node *curr = mp[key];
            mp.erase(key);
            deleteNode(curr);
        }
        if(mp.size() == cap)
        {
            mp.erase(tail -> prev -> key);
            deleteNode(tail -> prev);
        }
        
        addNode(new Node(key, value));
        mp[key] = head -> next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */