/*
    Problem Link: https://leetcode.com/problems/lru-cache/
*/

// Doubly linked list node
class Node {
public:
    int key;
    int value;
    Node *next;
    Node *prev;
    
    // param ctor
    Node(int key, int value) {
        this->key = key;
        this->value = value;
    }
};

class LRUCache {
    /*
        NOTATION: The nodes from left to right are the latest used ones
        The nearest node to the tail ie. the right-most node is the least recently used one
    */
    Node *head = new Node(-1, -1); // dummy head node
    Node *tail = new Node(-1, -1); // dummy tail node
    
    int capacity; // total size of the cache allowed
    // indicates the location address of the nodes present in the cache
    unordered_map<int, Node*> m; // {key -> node pointer}
public:
    
    LRUCache(int capacity) {
        this->capacity = capacity;
        // connect head with tail and vice-versa
        head->next = tail;
        tail->prev = head;
    }
    
    // helper function to add a node just after the head node
    void addNode(Node *node) {
        node->next = head->next;
        node->prev = head;
        head->next = node;
        node->next->prev = node;
    }
    
    // helper function to delete node from the tail node
    void deleteNode(Node *node) {
        Node *prev_node = node->prev;
        prev_node->next = node->next;
        node->next->prev = prev_node;
    }
    
    int get(int key) {
        // check if the node exists in the cache
        if(m.find(key) != m.end()) {
            Node *result_node = m[key];
            int result_val = result_node->value;
            // now this node becomes the latest used node
            // delete the entry from cache ie. unordered_map
            m.erase(key);
            // delete the node from DLL
            deleteNode(result_node);
            // add the node after the head
            addNode(result_node);
            // add the entry {with new node address} in the cache ie. unordered_map
            m[key] = head->next;
            return result_val;
        }
        // the key doesn't exist in the cache
        return -1; 
    }
    
    void put(int key, int value) {
        // check if node exists in the cache: delete it since we have to insert it again
        if(m.find(key) != m.end()) {
            Node *result_node = m[key];
            // delete the entry from cache
            m.erase(key);
            // delete the node from DLL
            deleteNode(result_node);
        }
        // remove the last frequently used node if capacity is at max
        if(m.size() == capacity) {
            // remove the least recently used node 
            // ie. the node closest to the tail (right-most node)
            // delete the entry from cache
            m.erase(tail->prev->key);
            // delete the node from DLL
            deleteNode(tail->prev);
        }
        // add the node in DLL
        addNode(new Node(key, value));
        // add the entry in cache
        m[key] = head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */