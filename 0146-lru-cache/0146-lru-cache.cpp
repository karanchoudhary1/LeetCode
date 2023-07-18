class LRUCache {
public:
    vector<int> v;
    queue<int> q;
    map<int,int> m;
    int siz=0;
    LRUCache(int capacity) {
        siz=capacity;
        for(int i=0;i<=100001;i++) v.push_back(-1);
    }
    
    int get(int key) {
        if(v[key]!=-1) {
            q.push(key);
            m[key]++; 
        }
        return v[key];
    }
    
    void put(int key, int value) {
        m[key]++;
        q.push(key);
        while(m.size()>siz){
            m[q.front()]--;
            if(m[q.front()]==0){
                m.erase(q.front());
                v[q.front()]=-1;
            }
            q.pop();
        }
        v[key]=value;
    }
};
