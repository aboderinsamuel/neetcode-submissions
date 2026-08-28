class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int n = nums.size();
        vector<int> myNums(2*n);

        for(int i=0; i<n; i++){
            myNums[i] = nums[i];
            myNums[i+n] = nums[i];
        }
        return myNums;
    }
};