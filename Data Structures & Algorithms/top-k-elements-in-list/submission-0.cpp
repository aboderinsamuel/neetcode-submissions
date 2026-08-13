class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> theMap;
        for(int num : nums){
            theMap[num]++;
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        for(auto& data : theMap){
            int number = data.first;
            int frequency = data.second;
            minHeap.push({frequency, number});

            if(minHeap.size() > k){
                minHeap.pop();
            }
        }
        vector<int> ans;
        while(!minHeap.empty()){
            ans.push_back(minHeap.top().second);
            minHeap.pop();
        }
        return ans;
    }
};
