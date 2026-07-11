#include<iostream>
#include<unordered_map>

using namespace std;


struct Node{
    int key;
    int value;
    Node* prev;
    Node* next;
    Node(int key, int value){
        this->key = key;
        this->value = value;
        this->prev = nullptr;
        this->next = nullptr;
    }
};


class LRUCache{
    private:
        int capacity;
        unordered_map<int, Node*> mp;
        Node* head;
        Node* tail;


        void add(Node* node){
            Node* nextNode = head->next;
            head->next = node;
            node->prev = head;
            node->next = nextNode;
            nextNode->prev = node;
        }

        void remove(Node* node){
            node->prev->next = node->next;
            node->next->prev = node->prev;
        }


    public:
        LRUCache(int capacity) : capacity(capacity) {
            head = new Node(-1, -1);
            tail = new Node(-1, -1);
            head->next = tail;
            tail->prev = head;
        }

        void put(int key, int value){
            if(mp.find(key) != mp.end()){
                Node* node = mp[key];
                mp.erase(key);
                remove(node);
                delete node;
            }

            Node* node = new Node(key, value);
            mp[key] = node;
            add(node);

            // Make sure to remove the cache entries as well...
            if(mp.size() > capacity){
                Node* delNode = tail->prev;
                remove(delNode);
                mp.erase(delNode->key);
                delete delNode;
            } 
        }

        int get(int key){
            if(mp.find(key) == mp.end()){
                return -1;
            }
        
            Node* node = mp[key];
            // Here I am simply removing the node and again adding it so that it comes at the front of the list, in order to maintain the LRU property...
            remove(node);
            add(node);
            return node->value;
        }

        void printCache(){
            cout << "\n------The current status------\n";
            Node* node = this->head->next;
            while(node != this->tail){
                cout << node->key << "->" << node->value << endl;
                node = node->next;
            }
            cout << endl;
        }

};


int main(){
    int cap;
    cout << "\nEnter the capacity of the LRU Cache : ";
    cin >> cap;
   
    LRUCache lru = LRUCache(cap);
    
    int countOfEntries;
    cout << "\nEnter the number of entries to simulate the LRU Cache : \n";
    cin >> countOfEntries;

    int key, value;

    string s;

    for(int i = 0; i < countOfEntries; i++){
        cout << "cache entries >> ";
        cin >> s;
        if(s == "insert"){
            cin >> key >> value;
            lru.put(key, value);

        }
        else if(s == "extract"){
            cin >> key;
            cout << lru.get(key) << endl;
        }
        lru.printCache();
    }

    cout << "\nThe final state of the LRU Cache is : \n\n";
    lru.printCache();

}
