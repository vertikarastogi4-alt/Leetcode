class LRUCache {
public:
    list<pair<int,int>> dll;
    unordered_map<int, list<pair<int,int>>::iterator> mp;
    int cap;

    LRUCache(int capacity) {
        cap = capacity;
    }

    int get(int key) {
        if(mp.find(key) == mp.end()) {
            return -1;
        }

        auto it = mp[key];
        int value = it->second;

        dll.erase(it);
        dll.push_front({key, value});

        mp[key] = dll.begin();

        return value;
    }

    void put(int key, int value) {
        if(mp.find(key) != mp.end()) {
            dll.erase(mp[key]);
        }
        else if(dll.size() == cap) {
            int oldKey = dll.back().first;
            dll.pop_back();
            mp.erase(oldKey);
        }

        dll.push_front({key, value});
        mp[key] = dll.begin();
    }
};
/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */