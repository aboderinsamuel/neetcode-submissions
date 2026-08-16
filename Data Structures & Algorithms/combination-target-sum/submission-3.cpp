class Solution {
public:
    void backtrack(vector<int>& nums, int target, int begin, vector<int>& current, vector<vector<int>>& result){
        if(target == 0){
            result.push_back(current);
            return;
        }
        for(int i=begin; i<nums.size(); i++){
            if(nums[i] > target) break;
            current.push_back(nums[i]);
            backtrack(nums, target-nums[i], i, current, result);
            current.pop_back();

        }
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        vector<int> current;
        sort(nums.begin(), nums.end());
        backtrack(nums, target, 0, current, result);
        return result;
    }
};
