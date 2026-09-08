class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xorAll = 0;

        for(int num : nums){
            xorAll ^= num;
        }
        int diffBit = xorAll & (-xorAll);
        int a = 0;
        int b = 0;
        for(int num : nums){
            if(num & diffBit){
                a ^= num;
            }
            else{
                b ^= num;
            }
        }
        return {a, b};
    }
};