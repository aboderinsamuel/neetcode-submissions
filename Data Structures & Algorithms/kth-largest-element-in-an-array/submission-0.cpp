class Solution {
private:
    int k;
    priority_queue<int, vector<int>, greater<int>> minHeap;
public:
    int findKthLargest(vector<int>& nums, int k) {
        this->k = k;
        for(int num : nums){
            minHeap.push(num);
            if(minHeap.size() > k){
                minHeap.pop();
            }
        }
        return minHeap.top();
    }
};
