class MyHashMap {
private:
    int num_buckets;
    vector<vector<pair<int, int>>> buckets;

    int hash(int key){
        return key % num_buckets;
    }
public:
    MyHashMap() {
        num_buckets = 10007;
        buckets.resize(num_buckets);
    }
    
    void put(int key, int value) {
        int index = hash(key);
        auto& bucket = buckets[index];
        for(auto& element: bucket){
            if(element.first == key){
                element.second = value;
                return;
            }
        }
        bucket.push_back({key, value});
    }
    
    int get(int key) {
        int index = hash(key);
        auto& bucket = buckets[index];
        for(auto& element : bucket){
            if(element.first == key){
                return element.second;
            }
        }
        return -1;
    }
    
    void remove(int key) {
        int index = hash(key);
        auto& bucket = buckets[index];
        for(auto it=bucket.begin(); it != bucket.end(); it++){
            if(it->first == key){
                bucket.erase(it);
                return;
            }
        }

    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */