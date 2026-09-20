class Solution {
public:
    int jump(vector<int>& nums) {
        int current_jump_Reach = 0;
        int maxReach = 0;
        int jumps = 0;
        for(int i=0; i<nums.size()-1; i++){
            maxReach = max(maxReach, i+nums[i]);
            if(i == current_jump_Reach){
                jumps++;
                current_jump_Reach = maxReach;
            }
        }
        return jumps;
    }
};
