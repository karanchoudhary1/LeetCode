class LRUCache {
public:
    
    queue<int> q;
    int siz;
    map<int,pair<int,int>> m;
    LRUCache(int capacity) {
        siz=capacity;
    }
    
    int get(int key) {
        if(m.find(key)!=m.end() && m[key].second!=-1){
        q.push(key);
        auto it=m[key];
        m[key]={it.first+1,it.second};
        return m[key].second;
        }
        //else m[key]={1,-1};
        return -1;
    }
    
    void put(int key, int value) {
        q.push(key);
        if(m.find(key)!=m.end()){
        auto it=m[key];
        m[key]={it.first+1,value};
        }
        else m[key]={1,value};
        while(m.size()>siz){
            auto it=m[q.front()];
            if(it.first==1) {
                m.erase(q.front());
                q.pop();
            }
            else{
                m[q.front()]={it.first-1,it.second};
                q.pop();
            }
        }
        return;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */