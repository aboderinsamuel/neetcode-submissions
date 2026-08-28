class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int> myNums;
        for(int num : nums){
            myNums.push_back(num);
        }
        for(int num : nums){
            myNums.push_back(num);
        }
        return myNums;
    }
};