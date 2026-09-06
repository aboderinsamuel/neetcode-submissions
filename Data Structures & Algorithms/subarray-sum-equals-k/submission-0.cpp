class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<long long, int> count;
        count[0] = 1;
        long long current = 0;
        int result = 0;

        for(int x : nums){
            current  += x;
            if(count.count(current -k)){
                result += count[current - k];
            }
            count[current]++;
        }
        return result;
    }
};