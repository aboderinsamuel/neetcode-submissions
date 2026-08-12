class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> seen;
        for(int i=0; i<nums.size(); i++){
            int complement = target - nums[i];
            if(seen.count(complement)){
                return {seen[complement], i};
            }
             // If not found, insert current number and its index into the map
             seen[nums[i]] = i;
        }
        return {};
    }
};
