class LRUCache {
    using pii = pair<int,int>;
    list<pii> lst;
    map< int, list<pii>::iterator > mp;
    int c;
public:
    LRUCache(int capacity) {
        c = capacity;
    }
    
    int get(int key) {
        if(mp.count(key)) {
            list<pii>::iterator it = mp[key];
            int value = (*it).second;
            lst.erase(it);
            lst.push_front({key, value});
            mp[key] = lst.begin();
            return value;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(get(key) != -1) {
            lst.erase(mp[key]);
        }
        if(lst.size() == c) {
            auto k = lst.back().first;
            mp.erase(k);
            lst.pop_back();
        }
        lst.push_front({key, value});
        mp[key] = lst.begin();
    }
};
