class MyHashSet {
public:
    /** Initialize your data structure here. */
    MyHashSet() {
    }

    void add(int key) {
        hashSet[key] = true;
    }

    void remove(int key) {
        hashSet[key] = false;
    }

    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        return hashSet[key];
    }

private:
    bool hashSet[(int)1e+6 + 1] = {false};
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */