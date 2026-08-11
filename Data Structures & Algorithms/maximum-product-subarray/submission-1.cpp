class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int currMax = nums[0];
        int currMin = nums[0];
        int result = nums[0];

        for(int i=1; i<nums.size(); i++){
            int n = nums[i];
            int tempMax = max({n, currMin*n, currMax*n});
            currMin = min({n, currMin*n, currMax*n});
            currMax = tempMax;
            result = max(result, currMax);
        }
        return result;
    }
};
