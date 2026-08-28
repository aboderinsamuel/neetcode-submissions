class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> count;
        for(int num : nums){
            count[num]++;
        }
        for(auto& [number, frequency] : count){
            if(frequency > nums.size()/2){
                return number;
            }
        }
        return -1;
    }
};