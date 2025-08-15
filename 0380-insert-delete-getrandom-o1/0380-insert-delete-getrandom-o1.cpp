class RandomizedSet {
    vector<int> values;
    unordered_map<int, int> idx;

public:
    RandomizedSet() {}

    bool insert(int val) {
        if (idx.find(val) != idx.end())
            return false;
        values.push_back(val);
        idx[val] = values.size() - 1;
        return true;
    }

    bool remove(int val) {
        if (idx.find(val) == idx.end())
            return false;
        int curIdx = idx[val];
        idx[values.back()] = curIdx;
        values[curIdx] = values.back();
        values.pop_back();
        idx.erase(val);
        return true;
    }

    int getRandom() {
        if (values.size() == 0) return -1;
        int index = rand() % values.size();
        return values[index];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */