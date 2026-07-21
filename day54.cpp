#include <iostream>
#include <unordered_map>
using namespace std;
class Node {
public:
    int key,value;
    Node* prev;
    Node* next;
    Node(int k,int v)
    {
        key=k;
        value=v;
        prev=nullptr;
        next=nullptr;
    }
};
class LRUCache {
public:
    int capacity;
    unordered_map<int,Node*>m;
    Node* head;
    Node* tail;
    LRUCache(int capacity) {
        this->capacity=capacity;
        head=new Node(0,0);
        tail=new Node(0,0);
        head->next=tail;
        tail->prev=head;
    }
    void add(Node* node){
        node->next=head->next;
        node->prev=head;
        head->next->prev=node;
        head->next=node;
    }
    void remove(Node* node){
        Node* left=node->prev;
        Node* right=node->next;
        left->next=right;
        right->prev=left;
    }
    int get(int key) {
        if (m.find(key)==m.end()){
            return -1;
        }
        Node* node=m[key];
        remove(node);
        add(node);
        return node->value;
    }
    
    void put(int key, int value) {
        if (m.find(key)!=m.end()){
        
        Node* node=m[key];
        node->value=value;
        remove(node);
        add(node);
        return;
        }
        Node* node=new Node(key,value);
        m[key]=node;
        add(node);
        if (m.size()>capacity){
            Node* lru=tail->prev;
            remove(lru);
            m.erase(lru->key);
            delete lru;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */