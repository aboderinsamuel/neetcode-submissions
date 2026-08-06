class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int, int> count;
        for(int n : nums){
            count[n]++;
        }
        for(auto& [num, freq] : count){
            if(freq > 1){
                return num;
            }
        }
        return -1;
    }
};
