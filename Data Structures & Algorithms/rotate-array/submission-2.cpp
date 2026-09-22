class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;
        if(n <= 1) return;
        vector<int> result(n);
        for(int i=0; i<n; i++){
            int newPos = (i+k)%n;
            result[newPos] = nums[i];
        }
        nums = result;
    }
};