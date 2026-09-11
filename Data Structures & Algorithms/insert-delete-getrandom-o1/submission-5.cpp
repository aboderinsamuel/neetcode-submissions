class RandomizedSet {
private:
    vector<int> nums;
    unordered_map<int, int> valToIndex;
public:
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(valToIndex.count(val) > 0) return false;
        nums.push_back(val);
        valToIndex[val] = nums.size()-1;
        return true;
    }
    
    bool remove(int val) {
        if(valToIndex.count(val) == 0) return false;
        int indexToRemove = valToIndex[val];
        int lastElement = nums.back();

        nums[indexToRemove] = lastElement;
        valToIndex[lastElement] = indexToRemove;
        nums.pop_back();
        valToIndex.erase(val);
        return true;


    }
    
    int getRandom() {
        return nums[rand() % nums.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */