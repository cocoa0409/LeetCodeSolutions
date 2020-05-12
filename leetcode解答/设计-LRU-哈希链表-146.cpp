class LRUCache {
private:
    private:
        int cap;
        // 双链表：装着 (key, value) 元组
        list<pair<int, int>> cache;
        // 哈希表：key 映射到 (key, value) 在 cache 中的位置
        unordered_map<int, list<pair<int, int>>::iterator> map;
public:
    LRUCache(int capacity) {
        cap=capacity;
    }
    
    int get(int key) {
        if(map.count(key)!=1) return -1;
        else{
            int val = map[key]->second;
            cache.erase(map[key]);
            cache.emplace_front(key,val);
            map[key]=cache.begin();
            return val;
        }
    }
    
    void put(int key, int value) {
        if(map.count(key)!=1){
            if(cache.size()==cap){
                auto it=cache.end();
                it--;
                map.erase(it->first);
                cache.erase(it);
            }
            cache.emplace_front(key,value);
            map[key]=cache.begin();
            
        }
        else{
            cache.erase(map[key]);
            cache.emplace_front(key, value);
            map[key] = cache.begin();
        }
    }
};
