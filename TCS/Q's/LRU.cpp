 #include <bits/stdc++.h>
 using namespace std;
 class Node{
    public:
    int key;
    int val;
    Node* prev;
    Node* next;
    Node(int n ,int k){
        key=n;
        val=k;
        prev=NULL;
        next=NULL;

    }

 };

 class LRUCache{
    private:
   // declaration
    int capacity;
    unordered_map<int,Node*>mpp;

    Node* head;
    Node* tail;
    
public:
 //contructor;
    LRUCache(int n){
        capacity=n;
        head=new Node(-1,-1);
        tail=new Node (-1,-1);
        head->next=tail;
        tail->prev=head;

    }
    void deleteNode(Node* node){
        //Node* curr=node;
        node->prev->next=node->next;
        node->next->prev=node->prev;
        

    }
    void insert(Node* node){
        head->next->prev=node;
        node->next=head->next;
        head->next=node;
        node->prev=head;
        
    }
    int get(int key){
        if(mpp.find(key)==mpp.end()){
            return -1;
        }
        else{
            Node* store=mpp[key];
            deleteNode(store);
            insert(store);
            return store->val;
        }

    }
    void put(int key ,int val){
        // if already exist in mpp;
        if(mpp.find(key)!=mpp.end()){
            Node* store1=mpp[key];
            // Update value
            store1->val = val;
            deleteNode(store1);
            insert(store1);
            return ;


        }
        // size is full;
        if(mpp.size()==capacity){
            Node* lru=tail->prev;
            mpp.erase(lru->key);
            // remove from linked list
            deleteNode(lru);
            // Free memory
            delete lru;

        }
        // create Node;
        Node* newnode=new Node(key,val);
        mpp[key]=newnode;
        insert(newnode);
        
    }

    void display(){
        Node* curr=head->next;
        while(curr!=tail){
            cout<<curr->key<<"->"<<curr->val;
            curr=curr->next;
            cout<<endl;
        }


    }

 };

 int main(){
    LRUCache obj(3);

    obj.put(5, 100);
    obj.put(2, 300);
    obj.put(4, 900);

    cout << "Cache after insertion:" << endl;
    obj.display();

    cout << "Get 5: " << obj.get(5) << endl;

    cout << "\nCache after get(5):" << endl;
    obj.display();

    obj.put(7, 700);

    cout << "Cache after put(7,700):" << endl;
    obj.display();


    return 0;
 }
