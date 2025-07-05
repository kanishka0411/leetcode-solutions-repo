class Node{
    public:
    int data,val;
    Node *next;
    Node *prev;

    Node(){
        data=val=-1;
        next=prev=NULL;
    }

    Node(int key_,int value){
        data=key_;
        val=value;
        next=prev=NULL;
    }
};
class LRUCache {
private:
    int cap;
    map<int,Node*>mpp;
    Node*head;
    Node*tail;
   

    void deleteNode(Node *node){
        Node *nextNode=node->next;
        Node *prevNode=node->prev;

        nextNode->prev=prevNode;
        prevNode->next=nextNode;
      
    }

    void insertAtHead(Node *node){
        Node *nextNode=head->next;
        head->next=node;
        nextNode->prev=node;
        node->next=nextNode;
        node->prev=head;
    }


    public:
    LRUCache(int capacity) {
        cap=capacity;
        head=new Node();
        tail=new Node();
         head->next=tail;
         tail->prev=head;
    }
    
    int get(int key) {
        if(mpp.find(key)==mpp.end()){
            return -1;
        }
        Node *node=mpp[key];
        int val=node->val;
        deleteNode(node);
        insertAtHead(node);

        return val;
    }
    
    void put(int key, int value) {
        if(mpp.find(key)!=mpp.end()){
            Node *node=mpp[key];
            node->val=value;
            deleteNode(node);
            insertAtHead(node);
            return;
        }
        if(mpp.size()==cap){
            Node *node=tail->prev;
            mpp.erase(node->data);
            deleteNode(node);
        }

        Node *newNode=new Node(key,value);
        mpp[key]=newNode;
        insertAtHead(newNode);
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */