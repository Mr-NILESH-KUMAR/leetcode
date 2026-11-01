class LRUCache {
public:

list<pair<int,int>> L;
int size ;

    LRUCache(int capacity) {
        size = capacity;
    }
    
    int get(int key) {
        auto temp = L.begin();

        while(temp != L.end()){
            if(temp->first == key){
                int val = temp->second;
                L.splice(L.end(),L,temp);
                return val;
            }
            temp++;
        }
        return -1;
    }
    
    void put(int key, int value) {

        if(L.size()<size && get(key)==-1){
        L.push_back({key,value});
        return;
        } else{
            if(get(key)!=-1){
                auto temp = L.begin();
                while(temp!=L.end()){
                    if(temp->first == key){
                        temp ->second = value;
                    }
                    temp++;
                }
                return;
            }else{
                if(L.size()<size){
                    L.push_back({key,value});
                    return;
                }else{
                L.pop_front();
                L.push_back({key,value});
                return;
                }
            }
           
        }

    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */